// ex_6.cpp
// own version of strcmp
#include <iostream>
#include <string.h> // for strcmp()
using namespace std;

int main()
{
  int cmpstr(char*, char*);
  void comp_library(char*, char*);

  char* s1 = "abby";
  char* s2 = "betty";
  char* s3 = "charlie";
  char* s4 = "charlie";

  comp_library(s1, s2);
  comp_library(s2, s1);
  comp_library(s3, s1);
  comp_library(s1, s3);
  comp_library(s4, s4);

  return 0;
}
//--------------------------------------
int cmpstr(char* s1, char* s2)
{
  while( *s1 && (*s1 == *s2))
    {
      s1++; s2++;
    }
  if (*s1 > *s2)
    return 1;
  else if (*s2 > *s1)
    return -1;
  else
    return 0;
}
//--------------------------------------
void comp_library(char* s1, char* s2)
{
  cout << "Comparing '" << s1 << "' to '" << s2 << "'" << endl;
  cout << "cmpstr output: " << cmpstr(s1, s2) << endl;
  cout << "strcmp output: " << strcmp(s1, s2) << endl;
}
