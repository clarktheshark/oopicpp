// ex_1.cpp
// writing phone numbres
#include <iostream>
using namespace std;

struct phone_number 
{
  int area_code;
  int exchange;
  int number;
};

int main()
{
  int your_ac, your_exchange, your_number;
  cout << "Enter your area code, exchange, and number: ";
  cin >> your_ac >> your_exchange >> your_number;
  phone_number your_phone_number = {your_ac, your_exchange, your_number};
  phone_number my_phone_number = {212, 767, 8900};

  cout << "My number is (" << my_phone_number.area_code
       << ") " << my_phone_number.exchange
       << "-" << my_phone_number.number << endl;

  cout << "Your number is (" << your_phone_number.area_code
       << ") " << your_phone_number.exchange
       << "-" << your_phone_number.number << endl;
  return 0;
}
