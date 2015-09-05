// misq.cp
// member square() function for Distance
#include <iostream>
using namespace std;
/////////////////////////////////////
class Distance
{
private:
  int feet;
  float inches;
public: // constructor (no args)
  Distance() : feet(0), inches(0.0)
  { }
  Distance(int ft, float in) : feet(ft), inches(in)
  { }
  void showdist() // display distance
  { cout << feet << "\'-" << inches << '\"'; }
  float square(); // member function
};
//-------------------------------------
float Distance::square() // return square of the distance
{
  float fltfeet = feet + inches/12; // convert to float
  float feetsqrd = fltfeet * fltfeet; // find the square
  return feetsqrd; // return square feet
}
////////////////////////////////////////////
int main()
{
  Distance dist(3, 6.0); // two-arg constructor
  float sqft; 

  sqft = dist.square();

  cout << "\nDistance = "; dist.showdist();
  cout << "\nSquare = " << sqft << " square feet\n";
  return 0;
}
