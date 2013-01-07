#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Globals.h"

// Forward declaration = There will be such a struct.
struct SDL_Surface;

class GameWindow
{
public:

  //Ctor
  GameWindow(const int width, int height, int bitdepth);

  // Initializes the window.
  int Init();

  // Flips the surface
  int Flip();

  int Clear(Color color);

  int Width() const;
  int Height() const;

  // Dtor
  ~GameWindow();
protected:

private:
  int width;
  int height;
  int bitdepth;
  SDL_Surface* backBuffer;
};


#endif
