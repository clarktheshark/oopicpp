// ex_7.cpp
// back to calculator, templated for multiple
#include <iostream>
#include <stdlib.h> // for exit(), labs()
using namespace std;
/////////////////////////////////////////////////////
template <class T>
class Fraction
{
private:
  T num;
  T den;
public:
  Fraction();
  Fraction(T, T);
  Fraction operator + (Fraction);
  Fraction operator - (Fraction);
  Fraction operator * (Fraction);
  Fraction operator / (Fraction);
  void lowterms();
  friend ostream& operator << (ostream& s, Fraction f)
  {
    cout << f.num << '/' << f.den;
    return s;
  }
  friend istream& operator >> (istream& s, Fraction f)
  {
    char dummy;
    cout << "\nEnter fraction: ";
    cin >> f.num >> dummy >> f.den;
    return s;
  }
};
//------------------------------------------------------
template <class T>
Fraction<T>::Fraction()
{
  num = 0;
  den = 1;
}
//------------------------------------------------------
template <class T>
Fraction<T>::Fraction(T n, T d)
{
  num = n;
  den = d;
}
//-----------------------------------------------------
template <class T>
Fraction<T> Fraction<T>::operator + (Fraction f)
{
  T n = num * f.den + den * f.num;
  T d= den * f.den;
  Fraction r = Fraction(n, d);
  r.lowterms();
  return r;
}
//-----------------------------------------------------
template <class T>
Fraction<T> Fraction<T>::operator - (Fraction f)
{
  T n = num * f.den - den * f.num;
  T d = den * f.den;
  Fraction r = Fraction(n, d);
  r.lowterms();
  return r;
}
//----------------------------------------------------
template <class T>
Fraction<T> Fraction<T>::operator * (Fraction f)
{
  T n = num * f.num;
  T d = den * f.den;
  Fraction r = Fraction(n, d);
  r.lowterms();
  return r;
}
//----------------------------------------------------
template <class T>
Fraction<T> Fraction<T>::operator / (Fraction f)
{
  T n = num * f.den;
  T d = den * f.num;
  Fraction r = Fraction(n, d);
  r.lowterms();
  return r;
}
//-----------------------------------------------------
template <class T>
void Fraction<T>::lowterms()
{
  long tnum, tden, temp, gcd;

  tnum = labs(num); // use non-negative copies
  tden = labs(den);
  if(tden == 0)
    { cout << "\nIllegal fraction: division by 0"; exit(1); }
  else if(tnum == 0)
    { num = 0; den = 1; return; }

  while(tnum != 0)
    {
      if (tnum < tden)
	{ temp = tnum; tnum = tden; tden = temp; }
      tnum = tnum - tden;
    }
  gcd = tden;
  num = num / gcd;
  den = den / gcd;
}
///////////////////////////////////////////////////////
int main()
{
  Fraction<int> f1(1,5);
  Fraction<int> f2(1,4);

  cout << "\nFraction f1: " << f1;
  cout << "\nFraction f2: " << f2;
  
  cout << "\nf1 + f2 = " << f1 + f2;
  cout << "\nf1 - f2 = " << f1 - f2;
  cout << "\nf1 * f2 = " << f1 * f2;
  cout << "\nf1 / f2 = " << f1 / f2;
  cout << endl;

  Fraction<long> f3(1L, 10L);
  Fraction<long> f4(1L, 10L);
  cout << "\nFraction f3: " << f3;
  cout << "\nFraction f4: " << f4;
  cout << "\nf3 + f4 = " << f3 + f4;
  cout << "\nf3 - f4 = " << f3 - f4;
  cout << "\nf3 * f4 = " << f3 * f4;
  cout << "\nf3 / f4 = " << f3 / f4;
  cout << endl;
  return 0;
}
