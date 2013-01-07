#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

// Forward declaration = There will be such a struct.
struct SDL_Surface;

typedef int Color;

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

  int FillRectangle(SDL_Rect& rect, Color color);
  int FillRectangle(int x, int y, int width, int height, Color color);

  #pragma region Accessors

  inline const int Width() const { return width; }
  inline const int Height() const { return height; }
  
  #pragma endregion

  int Close();

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
