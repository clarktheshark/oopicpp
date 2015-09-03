// ptrstr.cpp
// displays a string with pointer notation
#include <iostream>
using namespace std;

int main()
{
  void dispstr(char*); // prototype
  char str[] = "Idle people have the least leisure.";

  dispstr(str);
  return 0;
}
//------------------------------------
void dispstr(char* ps)
{
  while(*ps) // until null character
    cout << *ps++;
  cout << endl;
}
