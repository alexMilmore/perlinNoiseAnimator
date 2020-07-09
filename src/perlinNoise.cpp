#include <iostream>
#include <vector>
#include <cmath>
#include "vector2.h"
#include "perlinVectorList.h"

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


// fade function 6t^5-15t^4+10t^3
double PerlinNoise::fadeFunction(const double& t) {
  double value;
  value = 6*pow(t, 5) - 15*pow(t, 4) + 10*pow(t, 3);
  return value;
}

// finds interpolated value of 4 dot products
double PerlinNoise::findValue(const int& x, const int& y, const int& xPrime, const int& yPrime) {
  Vector2 mem;

  double values[4];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mem = Vector2((x % xDetail) - xDetail*i, (y % yDetail) - yDetail*j);
      //cout << "fail time" << endl;
      //vectors->printData();
      values[i + j*2] = vectors->vectorList[(xPrime + i) + (yPrime + j)*width] * mem;
    }
  }

  //linear interp values
  double xWeight = fadeFunction((x % xDetail)/(double)xDetail);
  double yWeight = fadeFunction((y % yDetail)/(double)xDetail);
  double a = values[0] + xWeight*(values[1] - values[0]);
  double b = values[2] + xWeight*(values[3] - values[2]);
  double value = a + yWeight*(b - a);

  return value;
}

// creates the perlin noise data
void PerlinNoise::genNoise () {
  double perlinValue{0};
  // co-ordinates of the current square
  int xPrime{0};
  int yPrime{0};

  for (int x = 0; x < height - 1; x++) {
    for (int y = 0; y < width - 1; y++) {
      xPrime = x/xDetail;
      yPrime = y/yDetail;
      perlinValue = findValue(x, y, xPrime, yPrime);
      valueData.push_back(perlinValue);(10,10,10,10);
    }
  }
}

////////////////////////////// unit testing ////////////////////////////////

int main() {
  cout << "it's runnin" << endl;
  PerlinNoise perl(100, 100, 10, 10);
  perl.genNoise();
  //cout << perl.valueData.size() << endl;

  for (int x{0}; x < perl.valueData.size(); x++) {
    cout << perl.valueData[x] << endl;
  }


  return 0;
}
