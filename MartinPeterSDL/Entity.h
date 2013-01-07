#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Vector2.h"
#include "include\SDL.h"

class Entity
{
public:
  // Constructor
  Entity(const Vector2& position, const SDL_Rect& rect);

  // Updates the game object
  int virtual Update() = 0;

  // Draws the game object
  int virtual Draw() = 0;

protected:
  Vector2 position;
  SDL_Rect rect;
private:

};

#endif