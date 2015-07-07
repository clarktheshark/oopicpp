// ex_2.cpp
// modelling tollbooths
#include <iostream>
using namespace std;

class tollBooth
{
  unsigned int cars;
  double money_collected;

public: 
  tollBooth() : cars(0), money_collected(0)
  { }

  void payingCar()
  {
    cars++;
    money_collected += 0.50;
  }

  void nopayCar()
  {
    cars++;
  }

  void display() const
  {
    cout << "Cars: " << cars
	 << ", money collected: " << money_collected 
	 << endl;
  }
};

int main()
{
  char key;
  bool loop = true;
  tollBooth t;

  while (loop){
    cout << "Enter car action: "; cin >> key;

    switch(key)
      {
      case '1':
	{ 
	  t.payingCar();
	  cout << "After paying car: "; t.display(); cout << endl;
	  break;
	}
      case '2': 
	{
	  t.nopayCar();
	  cout << "After nonpaying car: "; t.display(); cout << endl;
	  break;
	}
      case 27: 
	{
	  cout << "Escaping" << endl;
	  loop = false;
	  break;
	}
      }
  }
  return 0;
}
