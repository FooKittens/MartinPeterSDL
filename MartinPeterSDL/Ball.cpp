#include "GameWindow.h"
#include "Ball.h"
#include "include\SDL.h"


Ball::Ball(const Vector2& position, const SDL_Rect& rect)
  :Entity(position, rect)
{
  ballColor = 0xFF0000;
  direction = Vector2(0, -1);
}

int Ball::Update()
{
  
  return 0;
}

int Ball::Draw(GameWindow* window)
{
  window->FillRectangle(&rect, ballColor);
  return 0;
}
