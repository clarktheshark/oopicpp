// ex_8.cpp
// serial number
#include <iostream>
using namespace std;

class widget
{
  static unsigned int num_parts;
  unsigned int serial_number;

public:

  widget()
  { serial_number = ++num_parts; }

  void display() const
  {
    cout << "Widget, serial number: " << serial_number << endl;
  }
};
//-----------------------------------------------
unsigned int widget::num_parts = 0;
//////////////////////////////////////
int main()
{
  widget w1;
  w1.display();
  widget w2;
  w2.display();
  widget w3;
  w3.display();
  return 0;
}
