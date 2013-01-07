#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2
{
  float X;
  float Y;
};

// Vector2 addition
const Vector2& operator+(const Vector2& v1, const Vector2& v2);

// Vector2 subtraction
const Vector2& operator-(const Vector2& v1, const Vector2& v2);



#endif