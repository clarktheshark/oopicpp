// ex_6.cpp
// asdfasdfasdf
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

  void print_time(timez);
  long time_to_secs(timez);
  timez secs_to_time(long);
  timez get_time_from_user(int);

  timez t1, t2, t3;
  t1 = get_time_from_user(1);
  t2 = get_time_from_user(2);

  long t1_seconds = time_to_secs(t1);
  long t2_seconds = time_to_secs(t2);
  t3 = secs_to_time(t1_seconds + t2_seconds);

  print_time(t1);
  cout << " + " << endl;
  print_time(t2);
  cout << " = " << endl;
  print_time(t3);
  cout << endl;
  return 0;
}

timez get_time_from_user(int time_number){
  timez t1;
  cout << "Enter time " << time_number << " hours: "; cin >> t1.hours;
  cout << "Enter time " << time_number << " minutes: "; cin >> t1.minutes;
  cout << "Enter time " << time_number << " seconds: "; cin >> t1.seconds;
  return t1;
}

void print_time(timez t1)
{
  cout << t1.hours << ":" << t1.minutes << ":" << t1.seconds;
}

long time_to_secs(timez t1)
{
  return t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
}

timez secs_to_time(long secs)
{
  timez t1;
  t1.hours = secs / 3600;
  secs -= t1.hours * 3600;
  t1.minutes = secs / 60;
  t1.seconds = secs % 60;
  return t1;
}
