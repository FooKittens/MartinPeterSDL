#ifndef GLOBALS_H
#define GLOBALS_H

class GameWindow;
typedef int Color;

// Application window reference
extern GameWindow* g_GameWindow;

// True while application is running
extern bool g_ApplicationRunning;

// Window settings
extern const int g_kScreenWidth;
extern const int g_kScreenHeight;
extern const int g_kBitDepth;
extern const Color g_ClearColor;

// Step time in game loop.
extern const int g_kDelayTime;


#endif