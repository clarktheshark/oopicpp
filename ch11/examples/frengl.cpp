// frengl.cpp
// friend overloaded + operator
#include <iostream>
using namespace std;
////////////////////////////////////////
class Distance // English Distance class
{
private:
  int feet;
  float inches;
public:
  Distance() // constructor(no args)
  { feet = 0; inches = 0.0; }
  Distance( float fltfeet) // constructor ( one arg)
  {
    feet = int(fltfeet);
    inches = 12*(fltfeet-feet);
  }
  Distance(int ft, float in)
  { feet = ft; inches = in;
  }
  void showdist()
  { cout << feet << "\'-" << inches << '\"'; }
  friend Distance operator + (Distance, Distance); // friend
};
//
Distance operator + (Distance d1, Distance d2) // add d1 to d2
{
  int f = d1.feet + d2.feet;
  float i = d1.inches + d2.inches; //add the inches
  if(i >= 12.0)
    { i -= 12.0; f++; }
  return Distance(f,i);
}
//-----------------------------------------------------
int main()
{
  Distance d1 = 2.5;
  Distance d2 = 1.25;
  Distance d3;
  cout << "\nd1 = "; d1.showdist();
  cout << "\nd2 = "; d2.showdist();

  d3 = d1 + 10.0;
  cout << "\nd3 = "; d3.showdist();
  d3 = 10.0 + d1;
  cout << "\nd3 = "; d3.showdist();
  cout << endl;
  return 0;
}
