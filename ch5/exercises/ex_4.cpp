// ex_4.cpp
// takes two distances, and returns the larger one
#include <iostream>
using namespace std;

struct Distance 
{
  int feet;
  float inches;
};

Distance getLargerDistance(Distance, Distance);

int main()
{
  Distance d1, d2, d3;
  cout << "Enter d1 feet: "; cin >> d1.feet;
  cout << "Enter d1 inches: "; cin >> d1.inches;
  cout << "Enter d2 feet: "; cin >> d2.feet;
  cout << "Enter d2 inches: "; cin >> d2.inches;

  d3 = getLargerDistance(d1, d2);
  cout << "Larger Distance: " << d3.feet << "\'-" << d3.inches << "\"\n";
  return 0;
}

Distance getLargerDistance(Distance d1, Distance d2)
{
  float d1_inches = d1.feet * 12 + d1.inches;
  float d2_inches = d2.feet * 12 + d2.inches;
  if (d1_inches > d2_inches)
    return d1;
  else
    return d2;
}
