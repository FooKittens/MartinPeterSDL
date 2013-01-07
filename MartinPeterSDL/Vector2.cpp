#include "Vector2.h"


const Vector2& operator+(const Vector2& v1, const Vector2& v2)
{
  Vector2 v;
  v.X = v1.X + v2.X;
  v.Y = v1.Y + v2.Y;
  return v;
}

const Vector2& operator-(const Vector2& v1, const Vector2& v2)
{
  Vector2 v;
  v.X = v1.X - v2.X;
  v.Y = v1.X - v2.Y;
  return v;
}