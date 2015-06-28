// showprim.cpp
// displays prime number distribution
#include <iostream>
using namespace std;

int main()
{
  const unsigned char WHITE = 219; // solid color(primes)
  const unsigned char GRAY = 176; // gray (non primes)
  unsigned char ch;

  for (int count = 0; count < 80 * 25 - 1; count++) // for each screen position
    {
      ch = WHITE; // assume it's prime
      for (int j = 2; j < count; j++) // divide by every integer from
	if (count % j == 0) // 2 on up; if remainder is 0,
	  {
	    ch = GRAY; // it's not prime
	    break; // break out of the inner loop
	  }
      cout << ch; // display the character
    }
  char dummy;
  cin >> dummy;
  return 0;
}
