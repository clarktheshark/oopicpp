// ex_11.cpp
// four-function calculator with classes
#include <iostream> // cout, cin
#include <stdlib.h> // exit, labs
using namespace std;

class fraction
{
  int num;
  int den;

public:
  void get_fraction()
  {
    char dummy_char;
    cout << "Enter fraction: ";
    cin >> num >> dummy_char >> den;
  }

  void fadd(const fraction f1, const fraction f2)
  {
    num = f1.num * f2.den + f1.den * f2.num;
    den = f1.den * f2.den;
  }

  void fsub(const fraction f1, const fraction f2)
  {
    num = f1.num * f2.den - f1.den * f2.num;
    den = f1.den * f2.den;
  }

  void fmul(const fraction f1, const fraction f2)
  {
    num = f1.num * f2.num;
    den = f1.den * f2.den;
  }

  void fdiv(const fraction f1, const fraction f2)
  {
    num = f1.num * f2.den;
    den = f1.den * f2.num;
  }

  void lowterms() // change ourself to lowest terms
  {
    long tnum, tden, temp, gcd;

    tnum = labs(num); // use non-negative copies
    tden = labs(den); // (needs cmath)
    if (tden == 0) // check for n/0
      { cout << "Illegal fraction: division by 0"; exit(1); }
    else if (tnum == 0) // check for 0/n
      { num = 0; den = 1; return; }

    // this 'while' loop finds the gcd of tnum and tden
    while(tnum != 0)
      {
	if (tnum < tden ) // ensure numerator larger
	  { temp = tnum; tnum = tden; tden = temp; } // swap them
	tnum -= tden; // subtract them
      }
    gcd = tden; // this is the greatest common divisor
    num = num / gcd; // divide both num and den by gcd
    den = den / gcd; // to reduce frac to lowest terms
  }

  void display()
  {
    lowterms();
    cout << num << '/' << den;
  }
};

int main()
{
  fraction f1, f2, f3;
  char cont = 'y';
  char op;

  while(cont != 'n')
    {
      f1.get_fraction();
      f2.get_fraction();
      cout << "Enter operator: "; cin >> op;
      switch(op)
	{
	case '+': f3.fadd(f1, f2); break;
	case '-': f3.fsub(f1, f2); break;
	case '*': f3.fmul(f1, f2); break;
	case '/': f3.fdiv(f1, f2); break;
	}

      cout << endl;
      f1.display(); cout << " " << op << " " << endl;
      f2.display(); cout << " = " << endl;
      f3.display(); cout << endl;
      cout << "Repeat? "; cin >> cont;
    }
  return 0;
}
