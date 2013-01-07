#ifndef BREAKOUT_H
#define BREAKOUT_H

struct SDL_Rect;
struct Vector2;
struct GameObject;
class Input;

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
  void MoveBall();
  void MovePaddle();

  GameObject* ball;
  GameObject* paddle;
  Input* inputManager;

  const int PaddleWidth;
  const int PaddleHeight;
  const int BallWidth;
  const int BallHeight;
};
#endif