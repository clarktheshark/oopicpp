// ex_12.cpp
// mod 4 function calculator
#include <iostream>
using namespace std;

struct fraction {
  int n;
  int d;
};

int main() {
  char op;
  fraction f1, f2, f3;
  cout << "Enter fraction 1: ";
  cin >> f1.n >> op >> f1.d;
  cout << "Enter fraction 2: ";
  cin >> f2.n >> op >> f2.d;
  cout << "Enter operation: ";
  cin >> op;

  switch(op)
    {
    case '+':
      {
	f3.n = (f1.n * f2.d + f1.d * f2.n);
	f3.d = f1.d * f2.d;
	break;
      }
    case '-':
      {
	f3.n = (f1.n * f2.d - f1.d * f2.n);
	f3.d = f1.d * f2.d;
	break;
      }
    case '*':
      {
	f3.n = f1.n * f2.n;
	f3.d = f1.d * f2.d;
	break;
      }
    case '/':
      {
	f3.n = f1.n * f2.d;
	f3.d = f1.d * f2.n;
	break;
      }
    }

  cout << f1.n << "/" << f1.d << " " << op << " "
       << f2.n << "/" << f2.d << " = "
       << f3.n << "/" << f3.d << endl;
  return 0;
}
