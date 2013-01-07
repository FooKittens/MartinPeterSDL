#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2
{
  float x;
  float y;
};

// Vector2 addition
const Vector2& operator+(const Vector2& v1, const Vector2& v2);

// Vector2 subtraction
const Vector2& operator-(const Vector2& v1, const Vector2& v2);

// Dot product
const float Dot(const Vector2& v1, const Vector2& v2);

// Scalar multiplication
const Vector2& operator*(const Vector2& v, const float scalar);

#endif