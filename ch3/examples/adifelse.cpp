// adifelse.cpp
// demonstates IF...ELSE with adventure program
#include <iostream>
using namespace std;
#include <stdio.h> // for getchar()

int main()
{
  char dir = 'a';
  int x = 10, y = 10;

  cout << "Type ENTER to quit\n";
  while (dir != '\n') // until Enter is typed
    { 
     cout << "\nYour location is " << x << ", " << y;
      cout << "\nPress direction key (n, s, e, w): ";

      dir = getchar(); // get character
      if (dir == 'n') // go north
	y--;
      else 
	if (dir == 's') // go south
	  y++;
	else
	  if (dir == 'e') // go east
	    x++;
	  else 
	    if (dir == 'w') // go west
	      x--;
    } // end while
  return 0;
} // end main
