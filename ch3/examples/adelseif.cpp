// adelseif.cpp
// demonstrates ELSE...IF with adventure program
#include <iostream>
using namespace std;

int main()
{
  char dir = 'a';
  int x = 10, y = 10;

  cout << "Type '.' to quit\n";
  while (dir != '.') // until '.' is typed
    {
      cout << "\nYour location is " << x << ", " << y;
      cout << "\nPress direction key (n,s,e,w): ";
      cin >> dir; // get character
      if (dir == 'n') // go north
	y--;
      else if (dir == 's') // go south
	y++;
      else if (dir == 'e') // go east
	x++;
      else if (dir == 'w') // go west
	x--;
    }
  return 0;
} // end main
