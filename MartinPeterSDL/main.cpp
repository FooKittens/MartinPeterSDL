#include <iostream>
#include "SDL.h"
#include "Globals.h"
SDL_Surface* buffer = NULL;

SDL_Event myEvent;

int Init();
int FlipAndClear();
int CleanUp();

int main(int argc, char* argv[])
{
  bool running = true;

  int x = 64;

  while(running)
  {
    
    SDL_Rect rect = {x, 64, 64, 64};
    SDL_FillRect(buffer, &rect, 0xFF0000); 

    Uint8* keys = SDL_GetKeyState(NULL);
    if(keys[SDLK_x])
    {
        x += 4;
    }

    while(SDL_PollEvent(&myEvent))
    {
      if(myEvent.type == SDL_QUIT)
      {
        running = false;
      }
      else if(myEvent.key.keysym.sym == SDLK_ESCAPE)
      {
        running = false;
      }
    }

    

    SDL_Delay(g_kDelayTime);
  }

  SDL_FreeSurface(buffer);
  SDL_Quit();

  return 0;
}

int Init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  buffer = SDL_SetVideoMode(
    g_kScreenWidth,
    g_kScreenHeight,
    g_kBitDepth,
    SDL_SWSURFACE
  );

  if(buffer == NULL)
  {
    return 1;
  }

  return 0;
}

int FlipAndClear()
{
  if(SDL_Flip(g_Buffer))
  {
    return 1;
  }
  
  SDL_FillRect(buffer, NULL, 0);
  return 0;
}

int CleanUp()
{
  SDL_FreeSurface(g_Buffer);
}
