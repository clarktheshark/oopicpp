// ex_9.cpp
// calculate permutations
#include <iostream>
using namespace std;

int main()
{
  int num_guests, num_seats;
  cout << "Enter number of guests: ";
  cin >> num_guests;
  cout << "Enter number of seats: ";
  cin >> num_seats;
  unsigned long pos_arr = 1;
  for (int i = 0; i < num_seats; i++) {
    pos_arr *= (num_guests - i);
  }
  cout << "Number possible arrangements: " << pos_arr << endl;
  return 0;
}
