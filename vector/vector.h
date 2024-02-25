#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
class Vector {
 public:
  float x, y;
  Vector(float x_input = 0, float y_input = 0);
  Vector operator+(const Vector &other) const;
  Vector operator-(const Vector &other) const;
  Vector operator*(float other) const;

  Vector operator/(float other) const;
  float mag();
  Vector norm();
  float dot(const Vector &other);
  friend std::ostream &operator<<(std::ostream &os, const Vector &p);
};
#endif