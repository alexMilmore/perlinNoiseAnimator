#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class FractImg {
public:
  sf::Image img;
  int width, height, size;

  int counter;

  int detail{10};
  int arrayX{0};
  int arrayY{0};
  map<pair<double,double>,pair<double,double>> vectorList;
  map<pair<double,double>,pair<double,double>> futureVectorList;

  int steps{0};

  FractImg(const int&, const int&) {}
  map<pair<double,double>,pair<double,double>> listGen() {}
  void permute() {}

  double dot(const pair<double,double>&, const pair<double,double>&) {}
  double fadeFunction(const double&) {}
  pair<double,double> vectGen() {}
  double findDotValue(const int&, const int&, const int&, const int&) {}
  sf::Color mapColour(const double&, const int& type) {}
  void genImg(const int&) {}
};

#endif
