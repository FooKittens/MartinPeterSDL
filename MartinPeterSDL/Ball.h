#ifndef BALL_H
#define BALL_H
#include "Entity.h"

typedef int Color;

class Ball : Entity
{
public:
  // Constructor
  Ball(const Vector2& position, const SDL_Rect& rect);

  int virtual Update(double deltaTime);

  int virtual Draw(GameWindow* window);

protected:

private:
  // Moves the ball
  void Move();

  Color ballColor;
  Vector2 direction;
  float ballSpeed;
};


#endif