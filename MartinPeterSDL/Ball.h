#ifndef BALL_H
#define BALL_H
#include "Entity.h"

class Ball : Entity
{
public:
  // Constructor
  Ball(const Vector2& position, const SDL_Rect& rect);

  int virtual Update();

  int virtual Draw(GameWindow* window);

protected:

private:

};


#endif