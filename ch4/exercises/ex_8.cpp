// ex_8.cpp
// fraction adding with structs
#include <iostream>
using namespace std;

struct fraction {
  int num;
  int denom;
};

int main()
{
  char d;
  fraction f1, f2, f3;
  cout << "Enter fraction 1: ";
  cin >> f1.num >> d >> f1.denom;
  cout << "Enter fraction 2: ";
  cin >> f2.num >> d >> f2.denom;

  f3.num = (f1.num * f2.denom) + (f1.denom * f2.num);
  f3.denom = f2.denom * f1.denom;
  cout << f1.num << "/" << f1.denom << " + "
       << f2.num << "/" << f2.denom << " = "
       << f3.num << "/" << f3.denom << endl;

  return 0;
}

