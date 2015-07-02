//ex_1.cpp
// write area calculator
#include <iostream>
using namespace std;

float circarea(float);

int main()
{
  float radius;
  float area;
  cout << "Enter radius: "; cin >> radius;
  area = circarea(radius);
  cout << "Area of circle with radius " << radius << ": " << area << endl;
  return 0;
}

float circarea(float r)
{
  return r * r * 3.14159;
}
