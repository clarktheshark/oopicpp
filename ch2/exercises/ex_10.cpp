// ex_10.cpp
// converts old brit stuff to new currency
#include <iostream>
using namespace std;

int main()
{
  int pounds, shillings, pence;
  double converted_pounds = 0;
  cout << "Enter pounds: ";
  cin >> pounds;
  converted_pounds += pounds;
  cout << "Enter shillings: ";
  cin >> shillings;
  converted_pounds += shillings / 20.0; 
  cout << "Enter pence: ";
  cin >> pence;
  converted_pounds += pence / 240.0;
  cout << "Decimal pounds = \x9c" << converted_pounds << endl;
  return 0;
}
