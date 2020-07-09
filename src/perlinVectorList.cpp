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

  PerlinVectorList(const int&, const int&, const int&, const int&);
  ~PerlinVectorList();

  void printData();
  void randomize();

  Vector2 getVector(int, int);
};

PerlinVectorList::PerlinVectorList(const int& imgWidth, const int& imgHeight, const int& xDetail, const int& yDetail) {
  width = imgWidth/xDetail;
  height = imgWidth/yDetail;

  size = width*height;
  randomize();
}

PerlinVectorList::~PerlinVectorList() {
  cout << "vectorList deleted" << endl;
}

void PerlinVectorList::printData() {
  for (int i{0}; i < size; i++) {
    cout << vectorList[i];
    if (i % 6 == 0) {
      cout << endl;
    }
  }
  cout << endl;
}

void PerlinVectorList::randomize() {
  cout << "randomized thingy" << endl;
  for (int i{0}; i < size; i++) {
    double mag;
    mag = 1;
    Vector2 newVect(mag);
    vectorList.push_back(newVect);
  }
}

Vector2 PerlinVectorList::getVector(int x, int y) {
  int index = x + y * width;
  return vectorList[index];
}

////////////////////////////// unit testing ////////////////////////////////
/*
int main() {
  PerlinVectorList newList(50,50,5,5);
  newList.printData();
  cout << "done" << endl;

  return 0;
}
*/
