#include <iostream>
#include "SDL.h"
#include "Globals.h"

int Init();
int FlipAndClear();
int CleanUp();

typedef int Color;

int main(int argc, char* argv[])
{
  if(Init())
  {
    printf("Error in initialize!");
  }

  while(g_ApplicationRunning)
  {
    if(FlipAndClear())
    {
      // TODO(Peter): Handle issues clearing the backbuffer.
    }

    SDL_Delay(g_kDelayTime);
  }

  CleanUp();

  return 0;
}

int Init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  g_Buffer = SDL_SetVideoMode(
    g_kScreenWidth,
    g_kScreenHeight,
    g_kBitDepth,
    SDL_SWSURFACE
  );

  if(g_Buffer == NULL)
  {
    return 1;
  }

  SDL_WM_SetCaption("P&M Breakout!", NULL);

  // Set to true so the main loop starts.
  g_ApplicationRunning = true;

  return 0;
}

/* Flips the backbuffer and clears
 * the buffer with g_kClearColor. */
int FlipAndClear()
{
  if(SDL_Flip(g_Buffer))
  {
    return 1;
  }
  
  SDL_FillRect(g_Buffer, NULL, g_kClearColor);
  
  return 0;
}

int CleanUp()
{
  SDL_FreeSurface(g_Buffer);
  SDL_Quit();

  return 0;
}
