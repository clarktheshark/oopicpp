// ex_9.cpp
// overloading bMoney << and >> operators
#include <iostream>
#include <cmath> // for labs
#include <stdlib.h> // for exit()
using namespace std;
///////////////////////////////////////////////
class fraction
{
private:
  float num;
  float den;
public:
  fraction();
  fraction(float, float);
  fraction operator + (fraction&);
  fraction operator - (fraction&);
  fraction operator * (fraction&);
  fraction operator / (fraction&);
  void lowterms();
  friend istream& operator >> (istream&, fraction&);
  friend ostream& operator << (ostream&, fraction&);
};
//---------------------------------------------
fraction::fraction()
{ num = 0; den = 0; }
//---------------------------------------------
fraction::fraction(float n, float d)
{ num = n; den = d; }
//----------------------------------------------
fraction fraction::operator + (fraction& f)
{
  float n = num * f.den + den * f.num;
  float d = den * f.den;
  fraction rf(n,d);
  rf.lowterms();
  return rf;
}
//---------------------------------------------
fraction fraction::operator - (fraction& f)
{
  float n = num * f.den - den * f.num;
  float d = den * f.den;
  fraction rf(n,d);
  rf.lowterms();
  return rf;
}
//--------------------------------------------
fraction fraction::operator * (fraction& f)
{
  float n = num * f.num;
  float d = den * f.den;
  fraction rf(n,d);
  rf.lowterms();
  return rf;
}
//--------------------------------------------
fraction fraction::operator / (fraction& f)
{
  float n = num * f.den;
  float d = den * f.num;
  fraction rf(n, d);
  rf.lowterms();
  return rf;
}
//--------------------------------------------
void fraction::lowterms()
{
  long tnum, tden, temp, gcd;
  
  tnum = labs(num); // use non-negative copies
  tden = labs(den); // (needs cmath)

  // check for existance of 0
  if(tden==0)
    { cerr << "\nIllegal fraction: division by 0\n"; exit(1); }
  else if(tnum==0)
    { num = 0; den = 1; return; }
  
  // find the gcd of tnum and tden
  while(tnum != 0)
    {
      if (tnum < tden) // ensure numerator larger
	{ temp = tnum; tnum = tden; tden = temp; } // swap them
      tnum -= tden; // subtract them
    }
  gcd = tden; // this is greatest common divisor
  num = num / gcd; // divide noth num and den by gcd
  den = den / gcd; // to reduce frac to lowest terms
}
//---------------------------------------------
istream& operator >> (istream& s, fraction& f)
{
  float n = -1;
  float d = -1;
  char dummy;
  while (true)
    {
      s >> n >> dummy >> d;
      if (d == 0)
	{
	  cout << "Denominator cannot be 0";
	  s.clear(ios::failbit);
	}
      if (s.good())
	{
	  f.num = n;
	  f.den = d;
	  s.ignore(15, '\n');
	  return s;
	}
      d = -1;
      s.clear();
      s.ignore(15, '\n');
      cout << "\nEnter fraction again: ";
    }
}
//---------------------------------------------
ostream& operator << (ostream& s, fraction& f)
{
  cout << f.num << '/' << f.den;
  return s;
}
///////////////////////////////////////////////
int main()
{
  char op;
  fraction f1,f2,f3;
  
  do
    {
      // get fraction 1
      cout << "\nEnter first fraction: ";
      cin >> f1;

      // Get op
      while(true)
	{
	  cout << "\nEnter operator: ";
	  cin >> op;
	  if (cin.good() && (op == '+' || op == '-' || op == '*' || op == '/'))
	    break;
	  else
	    {
	      cout << "Operator '" << op << "' invalid. Try again";
	    }
	}
      // Get fraction 2
      cout << "\nEnter second fraction: ";
      cin >> f2;
      
      // Answer:
      switch(op)
	{
	case '+': f3 = f1 + f2; break;
	case '-': f3 = f1 - f2; break;
	case '*': f3 = f1 * f2; break;
	case '/': f3 = f1 / f2; break;
	}
      cout << "\n" << f1 << ' ' << op << ' ' << f2 << " = " << f3;

      // Do another?
      cout << "\nDo another(y/n)?: ";
      cin >> op;
    } while (op != 'n');

  return 0;
}
