#include <iostream>
 #include "../lib/vector2.h"

using namespace std;

template<class T>
void check(T a, T b) {
  if (a == b) {
    cout << ".";
  }
  else {
    cout << "F";
  }
}

// TODO: all these references are kinda clunky
int main() {
  // declare pointers
  Vector2* vect;
  Vector2* vect2;
  Vector2* vect3;
  Vector2* vect4;

  vect = new Vector2(11, 15);
  vect2 = new Vector2(1, 15);
  *vect2 = *vect;
  check<Vector2>(*vect, *vect2);<Vector2>
  delete vect;
  delete vect2;
  vect3 = new Vector2();
  vect4 = new Vector2(22, 23);

  // test vector addition
  vect = new Vector2(12, 13);
  vect2 = new Vector2(10, 10);
  vect3 = new Vector2();
  vect4 = new Vector2(22, 23);
  *vect3 = *vect + *vect2;
  check<Vector2>(*vect3, *vect4);
  delete vect;
  delete vect2;
  delete vect3;
  delete vect4;

  // test vector subtraction
  vect = new Vector2(12, 13);
  vect2 = new Vector2(10, 10);
  vect3 = new Vector2();
  vect4 = new Vector2(2, 3);
  *vect3 = *vect - *vect2;
  check<Vector2>(*vect3, *vect4);
  delete vect;
  delete vect2;
  delete vect3;
  delete vect4;

  // test vector multiplication
  vect = new Vector2(1, 2);
  double a = 5;
  vect3 = new Vector2();
  vect4 = new Vector2(5, 10);
  *vect3 = *vect * 5;
  check<Vector2>(*vect3, *vect4);
  delete vect;
  delete vect2;
  delete vect3;

  // test dot product
  vect = new Vector2(1, 1);
  vect2 = new Vector2(2, 0);
  check<double>((*vect) * (*vect2), 2);
  delete vect;
  delete vect2;

  cout << endl;
  cout << "done" << endl;
  return 0;
}
