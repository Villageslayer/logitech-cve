
#include <windows.h>
#include <stdint.h>
#include <winternl.h>
#include "keyboard.h"
#pragma comment(lib, "ntdll.lib")

typedef struct {
		int unknown0;
		int unknown1;
		int button0;
		int button1;
		int button2;
		int button3;
		int button4;
		int button5;
} KEYBOARD_IO;


#define MOUSE_PRESS 1
#define MOUSE_RELEASE 2
#define MOUSE_MOVE 3
#define MOUSE_CLICK 4

static HANDLE g_input;
static IO_STATUS_BLOCK g_io;

BOOL g_found_keyboard;

static BOOL callkeyboard(KEYBOARD_IO* buffer)
{
	IO_STATUS_BLOCK block;
	return NtDeviceIoControlFile(g_input, 0, 0, 0, &block, 0x2A200C, buffer, sizeof(KEYBOARD_IO), 0, 0) == 0L;
}

static NTSTATUS device_initialize(PCWSTR device_name)
{
	UNICODE_STRING name;
	OBJECT_ATTRIBUTES attr;

	RtlInitUnicodeString(&name, device_name);
	InitializeObjectAttributes(&attr, &name, 0, NULL, NULL);

	NTSTATUS status = NtCreateFile(&g_input, GENERIC_WRITE | SYNCHRONIZE, &attr, &g_io, 0,
		FILE_ATTRIBUTE_NORMAL, 0, 3, FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT, 0, 0);

	return status;
}

BOOL keyboard_open(void)
{
	NTSTATUS status = 0;


	if (g_input == 0) {

		wchar_t buffer0[] = L"\\??\\ROOT#SYSTEM#0002#{1abc05c0-c378-41b9-9cef-df1aba82b015}";

		status = device_initialize(buffer0);
		if (NT_SUCCESS(status))
			g_found_keyboard = 1;
		else {
			wchar_t buffer1[] = L"\\??\\ROOT#SYSTEM#0001#{1abc05c0-c378-41b9-9cef-df1aba82b015}";
			status = device_initialize(buffer1);
			if (NT_SUCCESS(status))
				g_found_keyboard = 1;
		}
	}
	return status == 0;
}


void keyboard_close(void)
{
	if (g_input != 0) {
		ZwClose(g_input);
		g_input = 0;
	}
}




void press_key(int b0, int b1, int b2, int b3, int b4, int b5)
{
	KEYBOARD_IO io;
	io.unknown0 = 0;
	io.unknown1 = 0;
	io.button0 = b0;
	io.button1 = b1;
	io.button2 = b2;
	io.button3 = b3;
	io.button4 = b4;
	io.button5 = b5;
	
	

	
	if (!callkeyboard(&io)) {
		keyboard_close();
		keyboard_open();
	}
}

