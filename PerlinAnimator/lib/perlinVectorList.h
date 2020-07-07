#ifndef PERLINVECTORLIST_H
#define PERLINVECTORLIST_H

#include <iostream>
#include <vector>
#include <cmath>
#include "vector2.h"

using namespace std;

class PerlinVectorList {
public:
  // variables for vector array used in perlin noise algorithm
  int detail{0};

  int width{0};
  int height{0};
  int size{0};

  // list of vectors
  vector<Vector2> vectorList;
  vector<Vector2> velocityVectorList;

  PerlinVectorList(const int&, const int&, const int&, const int&) {}
  ~PerlinVectorList() {}

  void printData() {}
  void randomize() {}

  Vector2 getVector(int, int) {}
};

#endif
