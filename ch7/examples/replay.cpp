// replay.cpp
// gets four ages from user, displays them
#include <iostream>
using namespace std;

int main()
{
  int age[4]; // array 'age' of 4 ints
  for(int j = 0; j < 4; j++)
    {
      cout << "Enter an age: "; // get 4 ages
      cin >> age[j]; // access array element
    }
  for(int j = 0; j < 4; j++) // display 4 ages
    cout << "You entered " << age[j] << endl;
  return 0;
}
