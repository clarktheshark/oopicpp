// ex_5
// date class
#include <iostream>
using namespace std;

class date
{
  int month;
  int day;
  int year;
public:
  void getdate()
  {
    cout << "\nEnter month: "; cin >> month;
    cout << "Enter date: "; cin >> day;
    cout << "Enter year: "; cin >> year;
  }

  void display() const
  { cout << endl << month << '/' << day << '/' << year << endl; }
};

int main()
{
  date d1;
  d1.getdate();
  d1.display();
  return 0;
}
