// convert.cpp
// demonstrates return values, converts pounds to kg
#include <iostream>
using namespace std;
float lbstokg(float); // declarartion

int main()
{
  float lbs, kgs;
  cout << "\nEnter your weight in pounds: ";
  cin >> lbs;
  kgs = lbstokg(lbs);
  cout << "Your weight in kilgrams is " << kgs << endl;
  return 0;
}
//---------------------------------------
// lbstokg()
// converts pounds to kilograms
float lbstokg(float pounds)
{
  float kilograms = 0.453592 * pounds;
  return kilograms;
}
