#include "include\SDL.h"

#ifndef GLOBALS_H
#define GLOBALS_H

#define NULL 0


SDL_Surface* g_Buffer = NULL;

// Window Settings
const int g_kScreenWidth = 800;
const int g_kScreenHeight = 600;
const int g_kBitDepth = 32;


const int g_kDelayTime = 16;

// For clearing the backbuffer {Black}
const int g_kClearColor = 0;

#endif