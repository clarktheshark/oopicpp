// advenand.cpp
// demonstratesAND logical operator
#include <iostream>
using namespace std;
#include <stdlib.h> // for exit()

int main()
{
  char dir = 'a';
  int x = 10, y = 10;

  while (dir != '.')
    {
      cout << "\nYour location is " << x << ", " << y;
      cout << "\nEnter direction (n,s,e,w): ";
      cin >> dir; // get direction
      switch(dir)
	{
	case 'n': y--; break; // update coordinates
	case 's': y++; break;
	case 'e': x++; break;
	case 'w': x--; break;
	}
      if (x == 7 && y == 11) // if x is 7 and y is 11
	{
	  cout << "\nYou found the treasure!\n";
	  exit(0);
	}
    } // end while
  return 0;
}

