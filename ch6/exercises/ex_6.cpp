// ex_6.cpp
// extended employee class
#include <iostream>
using namespace std;
//////////////////////////////////////
enum etype {laborer, secretary, manager};

class date
{
  int month, day, year;
public:
  void get_date()
  {
    cout << "\nEnter month: "; cin >> month;
    cout << "Enter day: "; cin >> day;
    cout << "Enter year: "; cin >> year;
  }

  void display() const
  {
    cout << month << '/' << day << '/' << year;
  }
};

class employee
{
  int number;
  float salary;
  date start_date;
  etype type;
public:
  void getemploy()
  {
    cout << "\nGetting employee details";
    // number
    cout << "\nEnter number: "; cin >> number;
    // salary
    cout << "Enter salary: "; cin >> salary;
    // start date
    cout << "Enter start date";
    start_date.get_date();
    // employee type
    char t;
    cout << "Enter employee type (l,s,m): "; cin >> t;
    switch(t)
      {
      case 'l': type = laborer; break;
      case 's': type = secretary; break;
      case 'm': type = manager; break;
      }
  }

  void putemploy() const
  {
    cout << "\nEmployee number: " << number
	 << ", salary: $" << salary
	 << ", start date: ";
    start_date.display();
    cout << ", type: ";
    switch(type)
      {
      case laborer: cout << "laborer"; break;
      case secretary: cout << "secretary"; break;
      case manager: cout << "manager"; break;
      }
  }
};

/////////////////////////////////////////////
int main()
{
  employee e1, e2, e3;
  e1.getemploy();
  e2.getemploy();
  e3.getemploy();

  e1.putemploy();
  e2.putemploy();
  e3.putemploy();
  cout << endl;
  return 0;
}
