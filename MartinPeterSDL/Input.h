#ifndef INPUT_H
#define INPUT_H

typedef Uint8 Key;

class Input
{
public:
  bool KeyDown();
  bool KeyNewDown();
  bool KeyNewUp();
protected:

private:
  Uint8* keyboardState;
  Uint8* previousKeyboardState;
}
#endif