#include <iostream>

#include "vector.h"
using namespace std;
int main() {
  Vector v1(10, 20);
  Vector v2(11, 23);
  cout << v1 + v2 << endl;
}