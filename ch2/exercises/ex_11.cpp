// ex_11.cpp
// fuck with jutisfying stuff differently
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int s_1 = 12;
  int s_2 = 12;
  int s_3 = 20;
  int s_4 = 14;
  int s_5 = 5;

  cout << setw(s_1) << setiosflags(ios::left) << "Last name"
       << setw(s_2) << setiosflags(ios::left) << "First name"
       << setw(s_3) << setiosflags(ios::left) << "Street Address"
       << setw(s_4) << setiosflags(ios::left) << "Town"
       << setw(s_5) << setiosflags(ios::left) << "State" << endl;
  cout << setw(s_1 + s_2 + s_3 + s_4 + s_5) << setfill('.') << '.' << endl;
  cout << setfill(' ')
       << setw(s_1) << setiosflags(ios::left) << "Jones"
       << setw(s_2) << setiosflags(ios::left) << "Bernard"
       << setw(s_3) << setiosflags(ios::left) << "109 Pine Lane"
       << setw(s_4) << setiosflags(ios::left) << "Littletown"
       << setw(s_5) << setiosflags(ios::left) << "MI" << endl;
  cout << setw(s_1) << setiosflags(ios::left) << "O'brien"
       << setw(s_2) << setiosflags(ios::left) << "Coleen"
       << setw(s_3) << setiosflags(ios::left) << "121-A Alabama St."
       << setw(s_4) << setiosflags(ios::left) << "Bigcity" 
       << setw(s_5) << setiosflags(ios::left) << "IL" << endl;
  return 0;
}
