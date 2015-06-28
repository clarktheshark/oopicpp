// ex_2.cpp
// converts f to c or c to f
#include <iostream>
using namespace std;

int main()
{
  int conversion_type;
  cout << "Type 1 to convert Fahrenheit to Celsius, " << endl
       << "     2 to convert Celsius to Fahrenheit:";

  cin >> conversion_type;

  double temperature;
  switch(conversion_type)
    {
    case 1:
      cout << "Enter temperature in Fahrenheit: ";
      break;
    case 2:
      cout << "Enter temperature in Celcius: ";
      break;
    }
  cin >> temperature;
  switch(conversion_type)
    {
    case 1:
      cout << "In Celcius that's " << (temperature - 32) * 5.0/9.0;
      break;
    case 2:
      cout << "In Fahrenheit that's " << temperature * 1.8 + 32;
      break;
    }
  cout << endl;

  return 0;
}
