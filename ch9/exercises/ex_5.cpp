// ex_5.cpp

#include <iostream>
using namespace std;
const int LEN = 80;

////////////////////////////////////////////
class employee
{
private:
  char name[LEN];
  unsigned long number;
public:
  void getdata()
  {
    cout << "\nEnter last name: "; cin >> name;
    cout << "Enter number: "; cin >> number;
  }
  void putdata() const
  {
    cout << "\nName: " << name;
    cout << "\nNumber: " << number;
  }
};
///////////////////////////////////////////
enum period { hourly, weekly, monthly };
class employee2 : private employee
{
private:
  double compensation;
  period payperiod;
public:
  void getdata()
  {
    employee::getdata();
    cout << "Enter compensation: "; cin >> compensation;
    char p;
    cout << "Enter pay period (h, w, m): "; cin >> p;

    switch (p)
      {
      case 'h':
	payperiod = hourly;
	break;
      case 'w':
	payperiod = weekly;
	break;
      case 'm':
	payperiod = monthly;
	break;
      default:
	cout << "Error: Payperiod not recognized";
	break;
      }
  }
  void putdata() const
  {
    employee::putdata();
    cout << "\nCompensation: " << compensation;
    cout << "\nPay Period: ";
    switch (payperiod)
      {
      case hourly: cout << "Hourly"; break;
      case weekly: cout << "Weekly"; break;
      case monthly: cout << "Monthly"; break;
      }
    cout << endl;
  }

};
//////////////////////////////////////////
int main()
{
  employee2 e;
  cout << "\nEnter employee e data:";
  e.getdata();
  cout << "\n\nEmployee e data:";
  e.putdata();
  return 0;
}
