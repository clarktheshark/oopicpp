// fahren.cpp
// demonstrates cin, newline
#include <iostream>
using namespace std;

int main()
{
  int ftemp; // temperature in fahrenheit
  
  cout << "Enter temperature in fahrenheit: ";
  cin >> ftemp;
  int ctemp = (ftemp - 32) * 5 / 9;
  cout << "Equivalent in Celcius is: " << ctemp << '\n';
  return 0;
}
