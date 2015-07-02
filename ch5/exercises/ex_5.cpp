// ex_5.cpp
// 
#include <iostream>
using namespace std;

int main()
{
  long hms_to_secs(int, int, int);
  int hours, mins, secs;
  while (hours != 13)
    {
      cout << "Enter hours: "; cin >> hours;
      if (hours == 13)
	break;
      cout << "Enter minutes: "; cin >> mins;
      cout << "Enter seconds: "; cin >> secs;
      cout << "Number seconds: " << hms_to_secs(hours, mins, secs) << endl;
    }
  return 0;
}

long hms_to_secs(int hours, int minutes, int seconds){
  return hours * 3600 * minutes * 60 + seconds;
}
