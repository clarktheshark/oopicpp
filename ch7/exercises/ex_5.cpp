// ex_5.cpp
// fraction averager
#include <iostream>
using namespace std;

class fraction
{
  int num;
  int den;
public:
  fraction() : num(0), den(1)
  { }

  void get_f() {
    cout << "Entering fraction:\n"
	 << "Enter num: "; cin >> num;
    cout << "Enter den: "; cin >> den;
  }

  void disp() {
    cout << num << "/" << den;
  }

  void add_f(const fraction f2) {
    num = num * f2.den + f2.num * den;
    den *= f2.den;
  }

  void div(int i) {
    den *= i;
  }
};

int main()
{
  const int MAX = 100;
  fraction fractions[MAX];

  char more = 'y';
  int count = 0;
  do {
    fractions[count++].get_f();
    cout << "Enter more fractions? (y/n): "; cin >> more;
  } while (more != 'n' && count < MAX);

  fraction average;
  for (int i = 0; i < count; i++) {
    average.add_f(fractions[i]);
  }
  average.div(count);

  cout << "Average of fractions: ";
  average.disp();
  cout << endl;

  return 0;
}
