// ex_6.cpp
//
#include <iostream>
#include <stdlib.h> // for exit()
using namespace std;
const int LIMIT = 100;
////////////////////////////////////////////////////
class safearay
{
private:
  int arr[LIMIT];
public:
  int& operator [](int n) // note: return by reference
  {
    if ( n < 0 || n >= LIMIT )
      { cout << "\nIndex out of bounds"; exit(1); }
    return arr[n];
  }
};
/////////////////////////////////////////////////////////
class boundedarray : public
int main()
{
  return 0;
}
