// ex_11.cpp
// overloaded bMoney. overloaded >> and <<
#include <iostream>
#include <iomanip> // for setprecision
#include <stdlib.h> // for atof()
using namespace std;
////////////////////////////////////////////////
class bMoney
{
private:
  long double money;
public:
  bMoney();
  bMoney(char[]);
  explicit bMoney(long double);
  void getmoney();
  bMoney operator + (bMoney);
  bMoney operator - (bMoney);
  bMoney operator * (long double);
  bMoney operator / (bMoney);
  bMoney operator / (long double);
  friend bMoney operator * (long double, bMoney);
  friend bMoney operator / (long double, bMoney);
  friend istream& operator >> (istream&, bMoney&);
  friend ostream& operator << (ostream&, bMoney);
};
//----------------------------------------------
bMoney::bMoney()
{ money = 0; }
//----------------------------------------------
bMoney::bMoney(char c[])
{ money = atof(c); }
//----------------------------------------------
bMoney::bMoney(long double d)
{ money = d; };
//-----------------------------------------------
void bMoney::getmoney()
{ cout << "\nEnter money: $"; cin >> money; }
//-----------------------------------------------
bMoney bMoney::operator + (bMoney b)
{ return bMoney(money + b.money); }
//----------------------------------------------
bMoney bMoney::operator - (bMoney b)
{ return bMoney(money - b.money); }
//-----------------------------------------------
bMoney bMoney::operator * (long double d)
{ return bMoney(money * d); }
//------------------------------------------------
bMoney bMoney::operator / (bMoney b)
{ return bMoney(money / b.money); }
//------------------------------------------------
bMoney bMoney::operator / (long double d)
{ return bMoney(money / d); }
//----------------------------------------------
bMoney operator * (long double d, bMoney b)
{ return bMoney(d * b.money); }
//---------------------------------------------
bMoney operator / (long double d, bMoney b)
{ return bMoney(d / b.money); }
//----------------------------------------------
istream& operator >> (istream& s, bMoney& b)
{ 
  s >> b.money;
  return s;
}
//----------------------------------------------
ostream& operator << (ostream& s, bMoney b)
{
  s << "$" << setprecision(2) << fixed << b.money;
  return s;
}
////////////////////////////////////////////////
int main()
{
  bMoney b1;
  bMoney b2;
  long double d = 2;
  
  cout << "Enter money b1: $";
  cin >> b1;
  cout << "Enter money b2: $"; 
  cin >> b2;

  cout << "\nb1: " << b1;
  cout << "\nb2: " << b2;
  
  cout << "\n" << b1 << " + " << b2 << " = " << b1 + b2;
  cout << "\n" << b1 << " - " << b2 << " = " << b1 - b2;
  cout << "\n" << b1 << " * " << d << " = " << b1 * d;
  cout << "\n" << d << " * " << b1 << " = " << d * b1;
  cout << "\n" << b1 << " / " << b2 << " = " << b1 / b2;
  cout << "\n" << b1 << " / " << d << " = " << b1 / d;
  cout << "\n" << d << " / " << b1 << " = " << d / b1;
  cout << endl;

  return 0;
}
