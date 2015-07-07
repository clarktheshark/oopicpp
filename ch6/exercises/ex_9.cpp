// ex_9.cpp
// fraction class
#include <iostream>
using namespace std;

class fraction
{
  int num; 
  int den;

public:

  void get_fraction()
  {
    char dummy_char;
    cout << "Enter fraction: ";
    cin >> num >> dummy_char >> den;
  }

  void display() const
  { cout << num << '/' << den; }

  void set_from_fraction_addition(fraction f1, fraction f2)
  {
    num = (f1.num * f2.den + f1.den * f2.num);
    den = (f1.den * f2.den);
  }
};

int main()
{
  char cont = 'y';
  while (cont != 'n')
    {
      fraction f1, f2, f3;
      f1.get_fraction();
      f2.get_fraction();
      f3.set_from_fraction_addition(f1, f2);
      f1.display(); cout << " + ";
      f2.display(); cout << " = ";
      f3.display();

      cout << "\n\nContinue? "; cin >> cont;
    }

  return 0;
}
