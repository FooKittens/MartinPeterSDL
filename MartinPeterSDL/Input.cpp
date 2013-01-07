#include "SDL.h"
#include "Input.h"
#include "Globals.h"

void Input::Update()
{
  SDL_Event sdlEvent;

  while (SDL_PollEvent(&sdlEvent))
  {
    switch(sdlEvent.type)
    {
    case SDL_QUIT:
      g_ApplicationRunning = false;
      break;
    }
  }

  previousKeyboardState = keyboardState;
  
  keyboardState = SDL_GetKeyState(NULL);
}

bool Input::KeyDown(SDLKey key)
{
  if (keyboardState[key])
  {
    return true;
  }
  return false;
}

bool Input::KeyNewDown(SDLKey key)
{
  if (keyboardState[key] && !previousKeyboardState[key])
  {
    return true;
  }
  return false;
}