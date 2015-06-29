// ex_11.cpp
// adds time
#include <iostream>
using namespace std;

struct timez
{
  int hours;
  int minutes;
  int seconds;
};

int main()
{
  timez t1, t2, t3;
  cout << "Enter hours time 1: ";
  cin >> t1.hours;
  cout << "Enter minutes time 1: ";
  cin >> t1.minutes;
  cout << "Enter seconds time 1: ";
  cin >> t1.seconds;
 
  cout << "Enter hours time 2: ";
  cin >> t2.hours;
  cout << "Enter minutes time 2: ";
  cin >> t2.minutes;
  cout << "Enter seconds time 2: ";
  cin >> t2.seconds;

  unsigned long t1_seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
  unsigned long t2_seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
  unsigned long t3_seconds = t1_seconds + t2_seconds;
  t3.hours = (t3_seconds) / 3600;
  t3_seconds %= 3600;
  t3.minutes = (t3_seconds / 60);
  t3.seconds = t3_seconds % 60;

  cout << "Result: " << t3.hours << ":" << t3.minutes << ":" << t3.seconds << endl;
  return 0;
}
