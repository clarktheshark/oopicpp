// convert2.cpp
// eliminates unnecessary variables
#include <iostream>
using namespace std;
float lbstokg(float); // declaration

int main()
{
  float lbs;

  cout << "\nEtner your weight in pouds: ";
  cin >> lbs;
  cout << "Your weight in kilograms is " << lbstokg(lbs)
       << endl;
  return 0;
}
//--------------------------------------------
// lbstokg()
// converts pounds to kilograms
float lbstokg(float pounds)
{
  return 0.453592 * pounds;
}
