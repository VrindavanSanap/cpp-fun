#include "vector.h"

#include <cmath>
#include <iostream>
using namespace std;

Vector::Vector(float x_input, float y_input) {
  x = x_input;
  y = y_input;
};

// addition
Vector Vector::operator+(const Vector &other) const {
  return Vector(this->x + other.x, this->y + other.y);
}

// subtraction
Vector Vector::operator-(const Vector &other) const {
  return Vector(this->x - other.x, this->y - other.y);
}

// multiplication
Vector Vector::operator*(float other) const {
  return Vector(this->x * other, this->y * other);
}
// division
Vector Vector::operator/(float other) const {
  return Vector(this->x / other, this->y / other);
}

float Vector::mag() { return pow((pow(x, 2) + pow(y, 2)), 0.5); }

Vector Vector::norm() { return Vector(x, y) / this->mag(); }

float Vector::dot(const Vector &other) {
  return this->x * other.x + this->y * other.y;
}

std::ostream &operator<<(std::ostream &os, const Vector &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}
