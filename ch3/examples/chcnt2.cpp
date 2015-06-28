// chcnt2.cpp
// counts characters and words typed in
#include <iostream>
using namespace std;
#include <stdio.h> // for getchar()

int main()
{
  int chcount = 0;
  int wdcount = 1; // space between two words
  char ch;

  while ( (ch=getchar()) != '\n' ) // loop until Enter typed
    {
      if (ch == ' ') // if it's a space
	wdcount++; // count a word
      else // otherwise
	chcount++; //count a character
    } // display results
  cout << "\nWords=" << wdcount << endl
       << "Letters=" << chcount << endl;
  return 0;
}
