// frisq.cpp
// friend square() function for Distance
#include <iostream>
using namespace std;
///////////////////////////////////////////
class Distance
{
private:
  int feet;
  float inches;
public:
  Distance() : feet(0), inches(0.0) // constructor (no argss)
  { }
  Distance(int ft, float in) : feet(ft), inches(in)
  { }
  void showdist()
  { cout << feet << "\'-" << inches << '\"'; }
  friend float square(Distance);// friend function
};
//-------------------------------------------
float square(Distance d) // return square of this Distance
{
  float fltfeet = d.feet + d.inches/12; // convert to float
  float feetsqrd = fltfeet * fltfeet; // find the square
  return feetsqrd;
}
//////////////////////////////////////////////////////
int main()
{
  Distance dist(3, 6.0);
  float sqft; 

  sqft = square(dist);

  cout << "\nDistance = "; dist.showdist();
  cout << "\nSquare = " << sqft << " square feet\n";
  return 0;
}
