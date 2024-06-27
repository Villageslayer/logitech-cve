#include <windows.h>
#include "mouse.h"
#include <stdio.h>
#include <stdint.h>

// DLL entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        if (!keyboard_open()) {
			MessageBoxA(NULL, "Failed to open keyboard device", "Error", MB_ICONERROR);
			return FALSE;
		}
        break;
    case DLL_THREAD_ATTACH:
        if (!keyboard_open()) {
            MessageBoxA(NULL, "Failed to open keyboard device", "Error", MB_ICONERROR);
            return FALSE;   
        }
        break;
    case DLL_THREAD_DETACH:
        if (!keyboard_close) {
			MessageBoxA(NULL, "Failed to close keyboard device", "Error", MB_ICONERROR);
			return FALSE;
		}
        break;
    case DLL_PROCESS_DETACH:
        if (!keyboard_close) {
            MessageBoxA(NULL, "Failed to close keyboard device", "Error", MB_ICONERROR);
            return FALSE;
        }
        break;
    }
    return TRUE; // Successful DLL_PROCESS_ATTACH.
}

    // DLL function

