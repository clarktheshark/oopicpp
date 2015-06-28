// factor.cpp
// calculates factorials, demonstrates FOR loop
#include <iostream>
using namespace std;

int main()
{
  unsigned int numb;
  unsigned long fact = 1; // long for larger numbers
  cout << "Enter a number: ";
  cin >> numb; // get number

  for(int j = numb; j > 0; j--)
    fact *= j;
  cout << "Factorial is " << fact << endl;
  return 0;
}
