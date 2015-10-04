// ex_6.cpp
// template arrayover for use with multiple datatypes
// creates safe array (index values are checked before access)
// uses overloaded [] operator for both put and get
#include <iostream>
#include <stdlib.h> // for exit()
using namespace std;
const int LIMIT = 100;
/////////////////////////////////////////////////////////////////
template <class T>
class safearay
{
private:
  T arr[LIMIT];
public:
  T& operator [](int n) // note: return by reference
  {
    if( n < 0 || n >= LIMIT)
      { cout << "\nIndex out of bounds"; exit(1); }
    return arr[n];
  }
};
///////////////////////////////////////////////////////////
int main()
{
  safearay<int> sa1;
  for(int j = 0; j < LIMIT; j++)
    sa1[j] = j * 10;
  for(int j = 0; j < LIMIT; j++)
    {
      cout << "Element " << j << " is " << sa1[j] << endl;
    }

  safearay<float> sa2;
  for(int j = 0; j < LIMIT; j++)
    sa2[j] = j * 10.55;
  for(int j = 0; j < LIMIT; j++)
    {
      cout << "Element " << j << " is " << sa2[j] << endl;
    }
  return 0;
}
