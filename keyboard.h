#ifndef KEYBOARD_H
#define KEYBOARD_H

#ifdef BUILDING_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif


DLL_EXPORT BOOL keyboard_open(void);
DLL_EXPORT void keyboard_close(void);
DLL_EXPORT void press_key(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5);


#endif // KEYBOARD_H
