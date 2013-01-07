#include "SDL.h"
#include "Input.h"

class
{
  Uint8* keyboardState;
  Uint8* previousKeyboardState;

  const int Pressed = 0;

  void Update()
  {
    keyboardState = SDL_GetKeyState(NULL);
  }

  bool KeyDown(SDLKey key)
  {
    if (keyboardState[key])
    {
      return true;
    }
    return false;
  }
}