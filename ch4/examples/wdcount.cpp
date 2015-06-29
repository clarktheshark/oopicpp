// wdcount.cpp
// demonstrates enums, count words in phrase
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

enum itsaWord { NO, YES }; // NO = 0, YES = 1

int main()
{
  itsaWord isWord = NO; // YES when in a word, NO when in whitespace
  string phrase;

  cout << "Enter a phrase:\n";
  getline(cin, phrase);

  int wordcount = 0;
  cout << "phrase: " << phrase << endl;
  for (int i = 0; i < phrase.length(); i++){
    char ch = phrase[i]; // get character
    if (ch == ' ' || ch == '\r') // if white space
      {
	if (isWord == YES) // and doing a word,
	  { // then it's end of word
	    wordcount++; // count the word
	    isWord = NO; // reset the flag
	  }
      }
    else
      if (isWord == NO) // if start of word,
	isWord = YES; // then set falg
  }
  if (isWord == YES)
    wordcount++;
  cout << "\n---Word count is " << wordcount  << "-----\n";
  return 0;
}
