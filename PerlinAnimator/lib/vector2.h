#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

class Vector2 {
public:
  tuple<double,double> coords;

  // constructs vector from x and y values
  Vector2();
  Vector2(const double&);
  Vector2(const double&, const double&) {}


  Vector2 normalize();
  Vector2 operator + (const Vector2&) const {}
  Vector2 operator - (const Vector2&) const {}
  Vector2 operator * (const double&) const {}
  double operator * (const Vector2&) const {}

  friend ostream& operator << (ostream&, const Vector2&) {}
};

#endif
