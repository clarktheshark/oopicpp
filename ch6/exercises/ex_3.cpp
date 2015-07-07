// ex_3.cpp
// time class to dipaly and add
#include <iostream>
using namespace std;

class timez 
{
  int hours;
  int minutes;
  int seconds;

public:
  // constructors
  timez() : hours(0), minutes(0), seconds(0)
  { }
  timez(int h, int m, int s) : hours(h), minutes(m), seconds(s)
  { }

  void display() const
  { cout << hours << ":" << minutes << ":" << seconds << endl; }

  void add_time(timez t1, timez t2)
  { 
    seconds = t1.seconds + t2.seconds;
    if ( seconds > 59 ){
      minutes++;
      seconds -= 60;
    }
    minutes += t1.minutes + t2.minutes;
    if ( minutes > 59 ) {
      hours++;
      minutes -= 60;
    }
    hours += t1.hours + t2.hours;
  }
};

int main()
{
  const timez t1(5, 40, 40);
  const timez t2(6, 30, 30);
  timez t3;
  t3.add_time(t1,t2);

  cout << "Time 1:" << endl;
  t1.display();
  cout << "Time 2:" << endl;
  t2.display();
  cout << "Time 3:" << endl;
  t3.display();
  cout << endl;
}
