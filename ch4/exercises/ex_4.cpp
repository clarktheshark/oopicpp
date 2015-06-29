// ex_4.cpp
// employee info
#include <iostream>
using namespace std;

struct employee {
  int number;
  float comp;
};

int main()
{
  employee e1, e2, e3;
  cout << "Enter employee 1 info: ";
  cin >> e1.number >> e1.comp;
  cout << "Enter employee 2 info: ";
  cin >> e2.number >> e2.comp;
  cout << "Enter employee 3 info: ";
  cin >> e3.number >> e3.comp;

  cout << "Employee 1 number: " << e1.number << ", comp: " << e1.comp << endl;
  cout << "Employee 2 number: " << e2.number << ", comp: " << e2.comp << endl;
  cout << "Employee 3 number: " << e3.number << ", comp: " << e3.comp << endl;
  return 0;
}
