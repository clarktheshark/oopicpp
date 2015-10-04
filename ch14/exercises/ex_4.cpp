// ex_4.cpp
// swaps - interchanges values of two arguments
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////
template <class T, class X>
void swaps(T& t, X& x)
{
  T temp = t;
  t = x;
  x = temp;
}
//////////////////////////////////////////////////////
int main()
{
  int a = 5;
  float b = 10.2;
  
  cout << "Preswap:" << endl;
  cout << "A: " << a << ", B: " << b << endl;

  swaps(a,b);
  cout << "Postswap:" << endl;
  cout << "A: " << a << ", B: " << b << endl;
  cout << endl;
  return 0;
}
