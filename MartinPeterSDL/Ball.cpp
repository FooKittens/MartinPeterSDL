#include <cmath>
#include "GameWindow.h"
#include "Ball.h"
#include "include\SDL.h"
#include "Globals.h"


Ball::Ball(const Vector2& position, const SDL_Rect& rect)
  :Entity(position, rect)
{
  ballSpeed = 0.125f;
  ballColor = 0xFF0000;
  direction = Vector2(1, -1);
}

int Ball::Update(double deltaTime)
{
  if(position.x <= 0 || position.x >= g_kScreenWidth)
  {
    direction.x = -direction.x;
  }
  if(position.y <= 0 || position.y >= g_kScreenHeight)
  {
    direction.y = -direction.y;
  }

  position += direction * ballSpeed * deltaTime;


  return 0;
}

int Ball::Draw(GameWindow* window)
{
  rect.x = (int)(position.x + 0.5) - 5;
  rect.y = (int)(position.y + 0.5) - 5;
  rect.w = 10;
  rect.h = 10;
  window->FillRectangle(&rect, ballColor);
  return 0;
}
