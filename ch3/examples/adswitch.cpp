// adswitch.cpp
// demonstrates SWITCH with adventure program
#include <iostream>
using namespace std;

int main()
{
  char dir = 'a';
  int x = 10, y = 10;

  while (dir != '.')
    {
      cout << "\nYour location is " << x << ", " << y;
      cout << "\nEnter direction (n,s,e,w): ";
      cin >> dir; // get character
      switch(dir) // switch on it
	{
	case 'n': y--; break; // go north
	case 's': y++; break; // go south
	case 'e': x++; break; // go east
	case 'w': x--; break; // go west
	case '.': cout << "Exiting\n"; break; // '.'
	default: cout << "Try again\n"; // unknown char
	} // end switch
    } // end while
  return 0;
} // end main
