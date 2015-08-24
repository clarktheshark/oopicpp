// ex3.cpp
// time class with overloading capabilities
#include <iostream>
using namespace std;
class tm 
{
private:
  int hours;
  int minutes;
  int seconds;
public:
  tm() : hours(0), minutes(0), seconds(0)
  { }
  tm(int h, int m, int s): hours(h), minutes(m), seconds(s)
  { }
  void pad_zeros(int x) {
    if (x < 10)
      cout << 0;
    cout << x;
  }
  void display() {
    pad_zeros(hours);
    cout << ':';
    pad_zeros(minutes);
    cout << ':';
    pad_zeroes(seconds);
  }
  tm operator + (tm t) const {
    int s = seconds + t.seconds;    
  }
