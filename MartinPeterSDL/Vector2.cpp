#include "Vector2.h"

const Vector2 operator+(const Vector2& v1, const Vector2& v2)
{
  Vector2 v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  return v;
}

void operator+=(Vector2& v1, const Vector2& v2)
{
  v1.x += v2.x;
  v1.y += v2.y;
}

const Vector2 operator-(const Vector2& v1, const Vector2& v2)
{
  Vector2 v;
  v.x = v1.x - v2.x;
  v.y = v1.x - v2.y;
  return v;
}

const float Dot(const Vector2& v1, const Vector2& v2)
{
  return v1.x * v2.x + v1.y * v2.y;
}

const Vector2 operator*(const Vector2& v, const float scalar)
{
  Vector2 res;
  res.x = v.x * scalar;
  res.y = v.y * scalar;
  return res;
}