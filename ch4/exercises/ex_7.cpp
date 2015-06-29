// ex_7.cpp
// extended employees
#include <iostream>
using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

struct date {
  int month;
  int day;
  int year;
};

struct employee {
  int number;
  float comp;
  etype type;
  date first_date;
};

int main()
{
  string e1_display;
  char d1, e1_type;
  employee e1;
  cout << "Enter employee number: ";
  cin >> e1.number;

  cout << "Enter employee comp: ";
  cin >> e1.comp;

  cout << "Enter employee type: ";
  cin >> e1_type;
  switch(e1_type)
    {
    case 'l':
      {
	e1_type = laborer;
	e1_display = "laborer";
	break;
      }
    case 's':
      {
	e1.type = secretary; 
	e1_display = "secretary";
	break;
      }
    case 'm':
      {
	e1.type = manager;
	e1_display = "manager";
	break;
      }
    case 'a':
      {
	e1.type = accountant;
	e1_display = "accountant";
	break;
      }
    case 'e':
      {
	e1.type = executive; 
	e1_display = "executive";
	break;
      }
    case 'r':
      {
	e1.type = researcher;
	e1_display = "researcher";
	break;
      }
    }
  cout << "Enter date of first employment (mm / dd/ yyyy): ";
  cin >> e1.first_date.month >> d1 >> e1.first_date.day >> d1 >> e1.first_date.year;

  cout << "Employee 1: "
       << " number: " << e1.number
       << ", comp: " << e1.comp
       << ", type: " << e1_display
       << ", first date: " << e1.first_date.month << "/" << e1.first_date.day << "/" << e1.first_date.year << endl;
  return 0;
}
