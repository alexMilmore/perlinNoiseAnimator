#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "vector2.h"

class PerlinNoise {
public:
  int width{0};
  int height{0};
  int size{0};

  int xDetail{0};
  int yDetail{0};

  vector<double> valueData;

  PerlinVectorList * vectors;

  PerlinNoise(int, int, int, int);

  double fadeFunction(const double&);
  double findValue(const int&, const int&, const int&, const int&);
  void genNoise ();
};

PerlinNoise::PerlinNoise(int arrayWidth, int arrayHeight, int xRes, int yRes) {
  width = arrayWidth;
  height = arrayHeight;
  xDetail = xRes;
  yDetail = yRes;

  vectors = new PerlinVectorList(arrayWidth, arrayHeight, xRes, yRes);
}

#endif
