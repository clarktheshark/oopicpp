// ex_3.cpp
// set's smaller argument to 0
#include <iostream>
using namespace std;

void zeroSmaller(int&, int&);

int main()
{
  int a, b;
  cout << "Enter int 1: "; cin >> a;
  cout << "Enter int 2: "; cin >> b;
  zeroSmaller(a,b);
  cout << "Int 1: " << a << ", Int 2: " << b << endl;
  return 0;
}

void zeroSmaller(int& a, int& b)
{
  if (a < b)
    a = 0;
  else
    b = 0;
}
