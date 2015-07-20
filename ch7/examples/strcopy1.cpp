// strcopy1.cpp
// copies a string using a for loop
#include <iostream>
#include <cstring> // for strlen()
using namespace std;

int main()
{
  char str1[] = "Oh, Captain my Captain! "
    "our fearful trip is done";

 const int MAX = 80; // size of str2 buffer
 char str2[MAX]; // empty string

 int j;
 for (j = 0; j < strlen(str1); j++) // copy strlen characters
   str2[j] = str1[j];
 str2[j] = '\0'; // insert null at end
 cout << str2 << endl; // display str2
 return 0;
}
