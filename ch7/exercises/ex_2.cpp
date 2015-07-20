// ex_2.cpp
// employee class
#include <iostream>
using namespace std;

class employee
{
  string name;
  long number;
public:
  void getdata()
  {
    cout << "Enter name: "; cin >> name;
    cout << "Enter number: "; cin >> number;
  }

  void putdata()
  {
    cout << "Name: " << name << ", ID: " << number;
  }
};

int main()
{
  const int MAX_EMPLOYEES = 100;
  employee employees[MAX_EMPLOYEES];

  int employee_count = 0;
  char get_data = 'y';
  do {
    employees[employee_count++].getdata();
    cout << "Get more data? (y/n): "; cin >> get_data;
  } while (get_data != 'n' && employee_count < MAX_EMPLOYEES);

  for (int i = 0; i < employee_count; i++) {
    cout << "Employee " << i << ", ";
    employees[i].putdata();
    cout << endl;
  }
  return 0;
}
