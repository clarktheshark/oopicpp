// signtest.cpp
// tests signed and unsigned itegers
#include <iostream>
using namespace std;

int main()
{
  int signedVar = 1500000000; //signed
  unsigned int unsignedVar = 1500000000; // unsigned

  signedVar = (signedVar * 2) / 3; // calculation exceeds range
  unsignedVar = (unsignedVar * 2) / 3; // calculation within range
  
  cout << "signedVar = " << signedVar << endl; // wrong
  cout << "unsignedVar = " << unsignedVar << endl; // OK
  return 0;
}
