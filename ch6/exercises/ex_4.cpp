// ex_4.cpp
// employee class
#include <iostream>
using namespace std;

class employee
{
  int number;
  float comp;

public:
  void set_info(int n, float c)
  {
    number = n;
    comp = c;
  }

  void get_info() {
    cout << "Enter number: "; cin >> number;
    cout << "Enter comp: "; cin >> comp;
  }

  void display() const
  { cout << "Employee " << number << ", comp: " << comp << endl; }
};

int main()
{
  employee e1, e2, e3;
  e1.get_info();
  e2.get_info();
  e3.get_info();

  e1.display();
  e2.display();
  e3.display();

  return 0;
}

