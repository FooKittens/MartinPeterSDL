#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"

typedef Uint8 Key;

class Input
{
public:
  void Update();
  bool KeyDown(SDLKey key);
  bool KeyNewDown(SDLKey key);
  bool KeyNewUp(SDLKey key);
protected:

private:
  Uint8* keyboardState;
  Uint8* previousKeyboardState;
};
#endif