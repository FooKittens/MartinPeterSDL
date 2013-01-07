#ifndef BREAKOUT_H
#define BREAKOUT_H

struct SDL_Rect;
struct Vector2;
class Input;

typedef SDL_Rect Ball;
typedef SDL_Rect Paddle;

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
  Paddle* paddle;
  Input* inputManager;
  Vector2 ballPos;
  Vector2 paddlePos;

  const int PaddleWidth;
  const int PaddleHeight;
  const int BallWidth;
  const int BallHeight;
};
#endif