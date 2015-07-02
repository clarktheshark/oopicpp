// ex_2.cpp
// gets power of a number
#include <iostream>
using namespace std;

double power(double n, int p = 2);

int main()
{
  double n;
  int p;
  cout << "Enter number: "; cin >> n;
  cout << "Enter power: "; cin >> p;
  cout << "Answer: " << power(n,p) << endl;
}

double power(double n, int p)
{
  double out = 1;
  for (int i = 0; i < p; i++)
    {
      out *= n;
    }
  return out;
}
