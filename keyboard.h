#ifndef KEYBOARD_H
#define KEYBOARD_H

#ifdef BUILDING_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
typedef int BOOL;

__declspec(dllimport) BOOL keyboard_open(void);
__declspec(dllimport) void keyboard_close(void);
__declspec(dllimport) void press_key(int b0, int b1, int b2, int b3, int b4, int b5);


#endif // KEYBOARD_H
