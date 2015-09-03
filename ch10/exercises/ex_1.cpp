// ex_1.cpp
// read numbers from users, place in array of type float
// average the fuckers, use pointer notation
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
  const int MAX = 80;
  int count = 0;
  float nums[MAX];
  char more = 'y';
  char ans[MAX];

  // get numbers
  cout << endl;
  do {
    cout << "Enter number: ";
    cin >> *(nums+count++);
    cout << "Enter more numbers (y/n)?: "; cin >> more;
  } while (more != 'n' && count < MAX);
  // average
  float sum = 0;
  for( int i = 0; i < count; i++)
    {
      sum += *(nums+i);
    }
  cout << "\nAverage: " << sum / count << endl;

  return 0;

}
