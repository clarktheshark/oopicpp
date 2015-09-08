// ex_2.cpp
// friend overloaded * operator
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////
class Distance
{
private:
  int feet;
  float inches;
public:
  Distance()
  { feet = 0; inches = 0.0; }
  Distance( float ft )
  { 
    feet = int(ft);
    inches = 12 * (ft-feet);
  }
  Distance(int ft, float in)
  { feet = ft; inches = in; }
  void showdist()
  { cout << feet << "\'-" << inches << '\"'; }
  friend Distance operator * (Distance, Distance);
};
//
Distance operator * (Distance d1, Distance d2)
{
  float fltfeet1 = d1.feet + d1.inches/12;
  float fltfeet2 = d2.feet + d2.inches/12;
  return Distance( fltfeet1 * fltfeet2 );
}
///////////////////////////////////////////////////////////
int main()
{
  Distance d1(3, 3.5);
  Distance d2 = 4.32;
  Distance d3;

  d3 = d1 * d2;
  d3 = 7.5 * d2;
  d3 = d1 * 7.5;
  return 0;
}
