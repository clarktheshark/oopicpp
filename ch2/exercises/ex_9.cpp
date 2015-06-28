// ex_9.cpp
// takes two fractions, returns sum
#include <iostream>
using namespace std;

int main()
{
  int a, b, c, d;
  char e, f;
  cout << "Enter first fraction: ";
  cin >> a >> e >> b;
  cout << "Enter second fraction: ";
  cin >> c >> f >> d;
  cout << "Sum = " << a * d + b * c << '/' << b * d << endl;
  return 0;
}
