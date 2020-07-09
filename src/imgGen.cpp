#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "vector2.h"

using namespace std;

class FractImg {
  public:
      // image to be created
      sf::Image img;
      // dimentions of image
      int width, height, size;

      // array of perlin noise values
      double * pixelValues;

      // variables for counting stuff
      int counter{0};
      int steps{0};

      // variables for vector array used in perlin noise algorithm
      int detail{10};
      int arrayX{0};
      int arrayY{0};
      // perlin noise requires a list of vectors at a grid of points
      map<pair<double,double>,pair<double,double>> vectorList;
      // For smooth animation, we transition the perlin vectors between 2 random
      // vector lists
      map<pair<double,double>,pair<double,double>> futureVectorList;

      // funcitons
      FractImg(const int&, const int&);
      int findIndex(int, int);

      map<pair<double,double>,pair<double,double>> listGen();
      void permute();

      double dot(const pair<double,double>&, const pair<double,double>&);
      double fadeFunction(const double&);
      pair<double,double> vectGen();
      double findDotValue(const int&, const int&, const int&, const int&);
      double findNormalizedDotValue(const int&, const int&, const int&, const int&);
      sf::Color mapColour(const double&, const int& type);
      void genImg(const int&);
};

// constructor
FractImg::FractImg(const int& imWidth, const int& imHeight) {
  width = imWidth;
  height = imHeight;
  size = width*height;

  arrayX = width/detail;
  arrayY = height/detail;

  // seed random number genarator
  srand (time(NULL));

  img.create(width, height, sf::Color(255, 255, 255));

  vectorList = listGen();
  futureVectorList = listGen();

  // initialise pixel value array
  pixelValues = new double[size];
}

int FractImg::findIndex(int x, int y) {
  int index = x + y*width;
  return index;
}

// Generates a list of random vectors for perlin noise
map<pair<double,double>,pair<double,double>> FractImg::listGen() {
  map<pair<double,double>,pair<double,double>> list;

  for (int i = 0; i < arrayX; i++) {
    for (int j = 0; j < arrayY; j++) {
      list[{i,j}] = vectGen();
    }
  }
  return list;
}

// changes the list of vectors to allow animation
void FractImg::permute() {
  pair<double,double> workingVect;
  double workingX;
  double workingY;
  double magnitude;
  for (int i = 0; i < arrayX; i++) {
    for (int j = 0; j < arrayY; j++) {
      workingX = get<0>(vectorList[{i,j}]) + 0.1*(get<0>(futureVectorList[{i,j}]) - get<0>(vectorList[{i,j}]));
      workingY = get<1>(vectorList[{i,j}]) + 0.1*(get<1>(futureVectorList[{i,j}]) - get<1>(vectorList[{i,j}]));
      magnitude = sqrt(pow(workingX,2) + pow(workingY,2));
      workingX = workingX/magnitude;
      workingY = workingY/magnitude;
      workingVect = pair<double,double>{workingX, workingY};
      vectorList[{i,j}] = workingVect;
    }
  }

  steps++;
  if (steps > 20) {
    steps = 0;
    futureVectorList = listGen();
  }
}

// dot product
double FractImg::dot(const pair<double,double>& vect1, const pair<double,double>& vect2) {
  return get<0>(vect1)*get<0>(vect2) + get<1>(vect1)*get<1>(vect2);
}

// fade function 6t^5-15t^4+10t^3
double FractImg::fadeFunction(const double& t) {
  double value;
  value = 6*pow(t, 5) - 15*pow(t, 4) + 10*pow(t, 3);
  return value;
}

// Generates a random vecotor with magnitude 1
pair<double,double> FractImg::vectGen() {
  double theta = rand() * 3;
  theta = theta/180 * 3.14;
  pair<double,double> vect{sin(theta), cos(theta)};
  return vect;
}

// finds interpolated value of 4 dot products
double FractImg::findDotValue(const int& x, const int& y, const int& xPrime, const int& yPrime) {
  pair<double,double> mem;

  double values[4];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mem = {(x % arrayX) - arrayX*i, (y % arrayY) - arrayY*j};
      values[i + j*2] = dot(vectorList[{xPrime + i,yPrime + j}],mem);
    }
  }

  //linear interp values
  double xWeight = fadeFunction((x % arrayX)/(double)arrayX);
  double yWeight = fadeFunction((y % arrayY)/(double)arrayY);
  double a = values[0] + xWeight*(values[1] - values[0]);
  double b = values[2] + xWeight*(values[3] - values[2]);
  double value = a + yWeight*(b - a);
  //cout << value << endl;
  return value;
}

// finds interpolated value of 4 dot products
double FractImg::findDotValue(const int& x, const int& y, const int& xPrime, const int& yPrime) {
  pair<double,double> mem;

  double values[4];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mem = {(x % arrayX) - arrayX*i, (y % arrayY) - arrayY*j};
      values[i + j*2] = dot(vectorList[{xPrime + i,yPrime + j}],mem);
    }
  }

  //linear interp values
  double xWeight = fadeFunction((x % arrayX)/(double)arrayX);
  double yWeight = fadeFunction((y % arrayY)/(double)arrayY);
  double a = values[0] + xWeight*(values[1] - values[0]);
  double b = values[2] + xWeight*(values[3] - values[2]);
  double value = a + yWeight*(b - a);
  //cout << value << endl;
  return value;
}

// converts values to scale that works with colours
sf::Color FractImg::mapColour(const double& input, const int& type) {

  int value = (int)input + 40;
  sf::Color col;

  // Two colour colour scheme. Creates 2 shifting colours with a boundry in between
  if (type == 0) {
    col = sf::Color(value*3,0,256 - value*3);
  }

  // Shifting stripes, creates stripes moving across.
  if (type == 1) {
    value = value % 6;
    if (value == 0) {
      col = sf::Color(100,0,150);
    }
    else if (value == 2) {
      col = sf::Color(0,200,20);
    }
    else if (value == 4) {
      col = sf::Color(200,0,20);
    } else {
      col = sf::Color(250,250,250);
    }
  }
  return col;
}

// creates the image, pixel by pixel
void FractImg::genImg (const int& colourType) {
  for (int x = 0; x < width - 1; x++) {
    for (int y = 0; y < height - 1; y++) {
      sf::Color colVal;
      colVal = mapColour(findDotValue(x,y,x/arrayX,y/arrayY), colourType);
      img.setPixel(x,y, colVal);
    }
  }

}
