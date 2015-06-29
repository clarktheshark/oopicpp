// ex_3.cpp
// models room with 3 dimensions, finds room
#include <iostream>
using namespace std;

///////////////////////
struct Distance {
  int feet;
  double inches;
};

struct Volume {
  Distance x;
  Distance y;
  Distance z;
};
////////////////////////

int main()
{
  Volume v1;
  v1.x = {1, 3};
  v1.y = {2, 4};
  v1.z = {3, 5};
  float fx, fy, fz;
  fx = v1.x.feet + v1.x.inches / 12.0;
  fy = v1.y.feet + v1.y.inches / 12.0;
  fz = v1.z.feet + v1.z.inches / 12.0;

  cout << "Volume of v1: "
       << fx * fy * fz << " inches " << endl;
  return 0;
}
