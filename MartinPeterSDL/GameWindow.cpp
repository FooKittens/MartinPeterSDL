#include "GameWindow.h"
#include "include\SDL.h"

// Constructor
GameWindow::GameWindow(int width, int height, int bitdepth)
{
  this->width = width;
  this->height = height;
  this->bitdepth = bitdepth;
}

int GameWindow::Init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  backBuffer = SDL_SetVideoMode(width, height, bitdepth, SDL_SWSURFACE);

  if(backBuffer == NULL)
  {
    return 1;
  }

  SDL_WM_SetCaption("P&M Breakout!", NULL);

  return 0;
}

int GameWindow::Flip()
{
  if(SDL_Flip(backBuffer))
  {
    return 1;
  }
  return 0;
}

int GameWindow::Clear(Color color)
{
  SDL_FillRect(g_Buffer, NULL, color);
}