// ex_5.cpp
// enter in date, parse
#include <iostream>
using namespace std;

struct date {
  int month;
  int day;
  int year;
};

int main()
{
  char d1;
  date date1;
  cout << "Enter date (mm/dd/yyyy): ";
  cin >> date1.month >> d1 >> date1.day >> d1 >> date1.year;
  cout << "Date: " << date1.month << "/" << date1.day << "/" << date1.year << endl;
  return 0;
}
