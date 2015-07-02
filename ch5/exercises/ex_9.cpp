// ex_9.cpp
// swap two time structs
#include <iostream>
using namespace std;

struct timez
{
  int hours;
  int minutes;
  int seconds;
};

void swap(timez&, timez&);
void print_time(timez, timez);

int main()
{
  timez t1 = {5, 5, 5};
  timez t2 = {10, 10, 10};
  print_time(t1, t2);
  swap(t1, t2);
  print_time(t1, t2);
  return 0;
}

void swap(timez& t1, timez& t2)
{
  timez temp;
  temp = t1;
  t1 = t2;
  t2 = temp;
}

void print_time(timez t1){
  cout << t1.hours << ":" << t1.minutes << ":" << t1.seconds;
}
void print_time(timez t1, timez t2)
{
  cout << "Time 1: ";
  print_time(t1);
  cout << ", Time 2: ";
  print_time(t2);
  cout << endl;
}
