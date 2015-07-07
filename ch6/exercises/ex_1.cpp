// ex_1.cpp
//  class replicating int
#include <iostream>
using namespace std;

class Int
{
  int i;
public:
  Int() : i(0)
  { }

  Int(int init_i) : i(init_i)
  { }

  void display()
  { cout << "int: " << i; }

  Int add_int(Int add_i) {
    return Int(i + add_i.i); 
  }
};

int main()
{
  Int i3;
  Int i1(1);
  Int i2(3);
  i3 = i1.add_int(i2);

  cout << endl;
  cout << "Int i1: "; i1.display(); cout << endl;
  cout << "Int i2: "; i2.display(); cout << endl;
  cout << "Int i3: "; i3.display(); cout << endl;
  return 0;
}
