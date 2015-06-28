// ex_5.cpp
// takes input, writes non-0 if lowercase, 0 if uppercase
#include <iostream>
#include "ctype.h"
using namespace std;

int main()
{
  char letter;
  cout << "Enter a letter: ";
  cin >> letter;
  cout << endl << islower(letter) << endl;
  return 0;
}
