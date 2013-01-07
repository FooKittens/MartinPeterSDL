#include "include\SDL.h"

#include "GameWindow.h"
#include "Breakout.h"

extern GameWindow* g_GameWindow;

Breakout::Breakout()
{
  ball = new SDL_Rect;
  ball->x = 64;
  ball->y = 64;
  ball->w = 10;
  ball->h = 10;
}

int Breakout::Update()
{

  return 0;
}

int Breakout::Draw()
{
  g_GameWindow->FillRectangle(*ball, 0xFF0000);

  return 0;
}