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
  SDL_Init(SDL_INIT_VIDEO);
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
  if(SDL_FillRect(backBuffer, NULL, color))
  {
    return 1;
  }

  return 0;
}

int GameWindow::FillRectangle(SDL_Rect* rect, Color color)
{
  if(SDL_FillRect(backBuffer, rect, color))
  {
    return 1;
  }

  return 0;
}

int GameWindow::FillRectangle(int x, int y, int width, int height, Color color)
{
  SDL_Rect rect = { x, y, width, height };
  if(SDL_FillRect(backBuffer, &rect, color))
  {
    return 1;
  }

  return 0;
}

int GameWindow::Close()
{
  SDL_FreeSurface(backBuffer);

  SDL_Quit();

  return 0;
}

GameWindow::~GameWindow()
{
  Close();
  printf("GameWindow Closed!");
}
