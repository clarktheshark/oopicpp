// ex_7.cpp
// lat/long
#include <iostream>
using namespace std;

class angle
{
  int degrees;
  float minutes;
  char direction;
public:
  angle() : degrees(0), minutes(0.0), direction(' ')
  { get_angle(); }

  angle(int dg, float m, char dn) : degrees(dg), minutes(m), direction(dn)
  { }

  void get_angle()
  {
    cout << "\nEnter degrees: "; cin >> degrees;
    cout << "Enter minutes: "; cin >> minutes;
    cout << "Enter direction (N, S, E, W): "; cin >> direction;
  }
  void display() const
  { cout << degrees << "\u00B0" << minutes << '\'' << direction; }
};
/////////////////////////////////
int main()
{
  angle a1(179, 59.9, 'E');
  a1.display();
  while (true)
    {
      angle a2;
      a2.display();
    }
  return 0;
}
