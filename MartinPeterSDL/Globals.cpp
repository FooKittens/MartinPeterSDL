#include "Globals.h"

#define NULL 0

typedef int Color;

GameWindow* g_GameWindow = NULL;

// True while application is running
bool g_ApplicationRunning;

// Window Settings
const int g_kScreenWidth = 800;
const int g_kScreenHeight = 600;
const int g_kBitDepth = 32;

const int g_kDelayTime = 16;
const Color g_ClearColor = 0;