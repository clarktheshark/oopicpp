// nofri.cpp
// limitation to overloaded + operator
#include <iostream>
using namespace std;
///////////////////////////////////////////////////
class Distance // English Distance class
{
private:
  int feet;
  float inches;
public:
  Distance() : feet(0), inches(0.0) // constructor, no args
  { }
  Distance(float fltfeet) // convert float to Distance // feet is int part
  {
    feet = static_cast<int>(fltfeet);
    inches = 12*(fltfeet-feet); // inches is what's left
  }
  Distance(int ft, float in) // constructor, 2 args
  { feet = ft; inches = in; }
  void showdist()
  { cout << feet << "\'-" << inches << '\"'; }
  Distance operator + (Distance);
};
//---------------------------------------------------
Distance Distance::operator + (Distance d2)
{
  int f = feet + d2.feet; // add the feet
  float i = inches = d2.inches; // add the inches
  if (i >= 12.0)
    { i -= 12.0; f++; }
  return Distance(f, i);
}
/////////////////////////////////////////////////////
int main()
{
  Distance d1 = 2.5; // constructor coverts
  Distance d2 = 1.25; // float feet to Distance
  Distance d3;
  cout << "\nd1 = "; d1.showdist();
  cout << "\nd2 = "; d2.showdist();

  d3 = d1 + 10.0; // distance + float: OK
  cout << "\nd3 = "; d3.showdist();
  // d3 = 10.0 + d1; // float + Distance: ERROR
  // cout << "\nd3 = "; d3.showdist();
  cout << endl;
  return 0;
}
