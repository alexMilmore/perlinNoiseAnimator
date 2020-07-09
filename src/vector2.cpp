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
  Vector2(const double&, const double&);

  Vector2 normalize();
  Vector2 operator + (const Vector2&) const;
  Vector2 operator - (const Vector2&) const;
  Vector2 operator * (const double&) const;
  double operator * (const Vector2& src) const;
  bool operator == (const Vector2&) const;

  friend ostream& operator << (ostream&, const Vector2&);
};

// Constructors
Vector2::Vector2() {
  get<0>(coords) = 0;
  get<1>(coords) = 0;
}
// Creates a vector with a set magnitude pointing in a random direction
Vector2::Vector2(const double& magnitude) {
  double theta = rand() * 3;
  theta = theta/180 * 3.14;
  get<0>(coords) = sin(theta)*magnitude;
  get<1>(coords) = cos(theta)*magnitude;
}
Vector2::Vector2(const double& x, const double& y) {
  get<0>(coords) = x;
  get<1>(coords) = y;
}

// Functions
Vector2 Vector2::normalize() {
  double normalizationFactor = sqrt(pow(get<0>(coords),2) + pow(get<1>(coords),2));
  Vector2 normalizedVector(get<0>(coords)*normalizationFactor, get<1>(coords)*normalizationFactor);
  return normalizedVector;
}

// Operator overloading
Vector2 Vector2::operator + (const Vector2& obj) const {
  Vector2 addedVector(get<0>(coords) + get<0>(obj.coords), get<1>(coords) + get<1>(obj.coords));
  return addedVector;
}
Vector2 Vector2::operator - (const Vector2& obj) const {
  Vector2 subtractedVector(get<0>(coords) - get<0>(obj.coords), get<1>(coords) - get<1>(obj.coords));
  return subtractedVector;
}
Vector2 Vector2::operator * (const double& num) const {
  Vector2 multipliedVector(get<0>(coords) * num, get<1>(coords) * num);
  return multipliedVector;
}
double Vector2::operator * (const Vector2& obj) const {
  double dotProduct;
  dotProduct = get<0>(coords) * get<0>(obj.coords) + get<1>(coords) * get<1>(obj.coords);
  return dotProduct;
}
bool Vector2::operator == (const Vector2& obj) const {
  if((get<0>(coords) == get<0>(obj.coords)) && (get<1>(coords) == get<1>(obj.coords))) {
    return true;
  }
  return false;
}

ostream& operator << (ostream& output, const Vector2& obj) {
  output << "[" << get<0>(obj.coords) << "," << get<1>(obj.coords) << "]";
  return output;
}
