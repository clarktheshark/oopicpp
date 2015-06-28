// advenor.cpp
// demonstrates OR logical operator
#include <iostream>
using namespace std;
#include <stdlib.h> // for exit()

int main()
{
  char dir = 'a';
  int x = 10, y = 10;

  while (dir != '.') // quit on '.'
    {
      cout << "\n\nYour location is " << x << ", " << y;

      if (x < 5 || x > 15)
	cout << "\nBeware: dragons lurk here";
      cout << "\nEnter direction (n,s,e,w): ";
      cin >> dir;
      switch(dir)
	{
	case 'n': y--; break; // update coordinates
	case 's': y++; break; 
	case 'e': x++; break;
	case 'w': x--; break;
	} // end switch
    } // end while
  return 0;
} // end main()
