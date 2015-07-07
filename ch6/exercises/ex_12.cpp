// ex_12.cpp
// multiplication table with class from ex_11.cpp
#include <iostream> // cout, cin
#include <iomanip> // setw
#include <stdlib.h> // exit, labs
using namespace std;

class fraction
{
  int num;
  int den;

public:
  fraction() : num(0), den(1)
  { }

  fraction(int n, int d) : num(n), den(d)
  { }

  void set_fraction(int n, int d)
  { num = n; den = d; }

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
  int den;
  int w = 8;
  cout << "\nCreating multiplcation table";
  cout << "\nEnter denominator: "; cin >> den;

  // create header
  cout << setw(w);
  cout << ' ';
  for (int i = 1; i < den; i++)
    {
      f1.set_fraction(i, den);
      cout << setw(w);
      f1.display();
    }
  cout << endl;
  // dashed line
  cout << string((w + 5) * den, '-') << endl;
  // all other results
  for (int i = 1; i < den; i++)
    {
      f1.set_fraction(i, den);
      cout << setw(w);
      f1.display();

      for (int j = 1; j < den; j++) 
	{
	  f2.set_fraction(j, den);
	  f3.fmul(f1,f2);
	  cout << setw(w);
	  f3.display();
	}
      cout << endl;
    }
  return 0;

}
