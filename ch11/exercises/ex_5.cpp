// ex_5.cpp
#include <iostream>
using namespace std;
//////////////////////////////////////
class bMoney
{
private:
  long double money;
public:
  bMoney()
  { money = 0; }
  bMoney(long double m)
  { money = m; }
  void getmoney()
  {
    cout << "Enter money: $";
    cin >> money;
  }
  void putmoney()
  {
    cout << "$" << money;
  }
  bMoney operator + (bMoney&);
  bMoney operator - (bMoney&);
  bMoney operator * (long double);
  bMoney operator / (bMoney&);
  bMoney operator / (long double);
  friend bMoney operator * (long double, bMoney&);
  friend bMoney operator / (long double, bMoney&);
};
/////////////////////////////////////////////////
bMoney bMoney::operator + (bMoney& b)
{ return bMoney(money + b.money); }
bMoney bMoney::operator - (bMoney& b)
{ return bMoney(money - b.money); }
bMoney bMoney::operator * (long double d)
{ return bMoney(money * d); }
bMoney bMoney::operator / (bMoney& b)
{ return bMoney(money / b.money); }
bMoney bMoney::operator / (long double d)
{ return bMoney(money / d); }
bMoney operator * (long double d, bMoney& b)
{ return bMoney( d * b.money); }
bMoney operator / (long double d, bMoney& b)
{ return bMoney( d / b.money); }
/////////////////////////////////////////////////////
int main()
{
  bMoney b1 ,b2;
  b1.getmoney();
  b2.getmoney();

  long double d = 2;

  // perform all seven operations
  cout << endl;
  b1.putmoney(); cout << " + "; b2.putmoney(); cout << " = "; (b1 + b2).putmoney(); cout << endl;
  b1.putmoney(); cout << " - "; b2.putmoney(); cout << " = "; (b1 - b2).putmoney(); cout << endl;
  b1.putmoney(); cout << " * "; cout << d << " = "; (b1 * d).putmoney(); cout << endl;
  b1.putmoney(); cout << " / "; b2.putmoney(); cout << " = "; (b1 / b2).putmoney(); cout << endl;
  b1.putmoney(); cout << " / "; cout << d << " = "; (b1 / d).putmoney(); cout << endl;
  cout << d << " * "; b1.putmoney(); cout << " = "; (d * b1).putmoney(); cout << endl;
  cout << d << " / "; b1.putmoney(); cout << " = "; (d / b1).putmoney(); cout << endl;
  return 0;
}
