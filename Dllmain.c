#include <windows.h>
#include "mouse.h"
#include <stdio.h>


// DLL entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        if (!mouse_open()) {
			MessageBoxA(NULL, "Failed to open mouse device", "Error", MB_ICONERROR);
			return FALSE;
		}
        break;
    case DLL_THREAD_ATTACH:
        if (!mouse_open()) {
            MessageBoxA(NULL, "Failed to open mouse device", "Error", MB_ICONERROR);
            return FALSE;   
        }
        break;
    case DLL_THREAD_DETACH:
        if (!mouse_close) {
			MessageBoxA(NULL, "Failed to close mouse device", "Error", MB_ICONERROR);
			return FALSE;
		}
        break;
    case DLL_PROCESS_DETACH:
        if (!mouse_close) {
            MessageBoxA(NULL, "Failed to close mouse device", "Error", MB_ICONERROR);
            return FALSE;
        }
        break;
    }
    return TRUE; // Successful DLL_PROCESS_ATTACH.
}

    // DLL function

