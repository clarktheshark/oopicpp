// ex_10.cpp
// ship number and location
#include <iostream>
using namespace std;
//////////////////////////////////////////////
class angle
{
  int degrees;
  float minutes;
  char direction;
public:
  void set_angle()
  {
    cout << "\nEnter degrees: "; cin >> degrees;
    cout << "Enter minutes: "; cin >> minutes;
    cout << "Enter direction: "; cin >> direction;
  }

  void display()
  { cout << degrees << "\u00B0" << minutes << "\' " << direction; }
};

class ship
{
  angle lat, lon;
  static unsigned int num_ships;
  unsigned int ship_id;

public:
  ship()
  { ship_id = ++num_ships;
    cout << "For ship: " << ship_id << endl;
    cout << "Enter lat: ";
    lat.set_angle();
    cout << "Enter lon: ";
    lon.set_angle();
  }

  void display()
  {
    cout << "Ship ID: " << ship_id
	 << ", lat: "; lat.display();
    cout << ", lon: "; lon.display();
  }
};
//---------------------------------------------------
unsigned int ship::num_ships = 0;
////////////////
int main()
{
  ship ship1, ship2, ship3;

  ship1.display(); cout << endl;
  ship2.display(); cout << endl;
  ship3.display(); cout << endl;
  return 0;
}
