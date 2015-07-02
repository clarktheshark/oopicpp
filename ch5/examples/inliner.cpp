// inliner.cpp
// demonstrates inline unfctions
#include <iostream>
using namespace std;

// lbstokg()
// converts pounds to kilgorams
inline float lbstokg(float pounds)
{
  return 0.453592 * pounds;
}
//----------------------------------------------
int main()
{
  float lbs;

  cout << "\nEnter your weight in pouds: ";
  cin >> lbs;
  cout << "YOur weight in kilograms is " << lbstokg(lbs)
       << endl;
  return 0;
}
