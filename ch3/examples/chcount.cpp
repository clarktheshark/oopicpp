// chcount.cpp
// counts characters and words typed in
#include <iostream>
using namespace std;
#include <stdio.h> // for getche()

int main()
{
  int chcount = 0; // counts non-space characters
  int wdcount = 1; //counts spaces between words
  char ch = 'a'; // ensure it isn't '\r'

  cout << "Enter a phrase: ";
  while ( ch != '\n') // loop until ENTER typed
    {
      ch = getchar(); // read one character
      if (ch == ' ') // if it's a space
	wdcount++;
      else
	chcount++; // coutn a character
    }
  cout << "\nWords=" << wdcount << endl
       << "Letters=" << (chcount-1) << endl;
  return 0;
}
