// convertCf.cpp
// converts gallons to cubic feet
#include <iostream>
using namespace std;

int main()
{
  const double gallonsPerCf = 7.481;
  double gallons;
  cout << "Enter number of gallons: ";
  cin >> gallons;
  cout << "Cf for " << gallons << " gallons: " << gallons / gallonsPerCf << endl;
  return 0;
}
