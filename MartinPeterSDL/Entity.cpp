#include "Entity.h"

// Constructor
Entity::Entity(const Vector2& position, const SDL_Rect& rect)
{
  this->position = position;
  this->rect = rect;
}
