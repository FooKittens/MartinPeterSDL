#include "SDL.h"
#include "Input.h"

void Input::Update()
{
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