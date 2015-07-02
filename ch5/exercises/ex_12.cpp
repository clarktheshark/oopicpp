// ex_12.cpp
// four function calculator with fractions
#include <iostream>
using namespace std;

struct fraction
{
  int num;
  int den;
};

fraction get_fraction();
void print_fraction(fraction);
fraction fadd(fraction, fraction);
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);

int main()
{
  fraction f1, f2, f3;
  char op;

  while (true)
    {
      f1 = get_fraction();
      if (f1.num == 0 || f1.den == 0)
	break;
      f2 = get_fraction();

      cout << "Enter operator: "; cin >> op;
      
      switch(op)
	{
	case '+': f3 = fadd(f1, f2); break;
	case '-': f3 = fsub(f1, f2); break;
	case '*': f3 = fmul(f1, f2); break;
	case '/': f3 = fdiv(f1, f2); break;
	}
      
      print_fraction(f1);
      cout << " + " << endl;
      print_fraction(f2);
      cout << " = " << endl;
      print_fraction(f3);
      cout << endl;
    }

  return 0;
}

fraction fadd(fraction f1, fraction f2)
{
  fraction f;
  f.num = f1.num * f2.den + f1.den * f2.num;
  f.den = f1.den * f2.den;
  return f;
}

fraction fsub(fraction f1, fraction f2)
{
  fraction f;
  f.num = f1.num * f2.den - f1.den * f2.num;
  f.den = f1.den * f2.den;
  return f;
}

fraction fmul(fraction f1, fraction f2)
{
  fraction f;
  f.num = f1.num * f2.num;
  f.den = f1.den * f2.den;
  return f;
}

fraction fdiv(fraction f1, fraction f2)
{
  fraction f;
  f.num = f1.num * f2.den;
  f.den = f1.den * f2.num;
  return f;
}

fraction get_fraction()
{
  fraction f;
  char dummy;
  cout << "Enter fraction: ";
  cin >> f.num >> dummy >> f.den;
  return f;
}

void print_fraction(fraction f)
{
  cout << f.num << "/" << f.den;
}
