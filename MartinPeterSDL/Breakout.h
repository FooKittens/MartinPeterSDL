#ifndef BREAKOUT_H
#define BREAKOUT_H

struct SDL_Rect;
typedef SDL_Rect Ball;

class Breakout
{
public:
  // Constructor
  Breakout();

  int Update();
  int Draw();

  // Destructor
  ~Breakout();
protected:

private:
  Ball* ball;

};
#endif