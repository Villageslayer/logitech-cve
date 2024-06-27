#ifndef MOUSE_H
#define MOUSE_H

#ifdef BUILDING_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif


DLL_EXPORT BOOL mouse_open(void);
DLL_EXPORT void mouse_close(void);
DLL_EXPORT void mouse_move(char button, char x, char y, char wheel)


#endif // MOUSE_H
