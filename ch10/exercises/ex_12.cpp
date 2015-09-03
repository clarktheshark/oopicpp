// ex_12.cpp
// float pointer simulation
#include <iostream>
using namespace std;
const int ARRAY_SIZE = 100;
float fmemory[ARRAY_SIZE];
int fmem_top = 0;
int pmemory[ARRAY_SIZE];
int pmem_top = 0;
//////////////////////////////////////
class Float
{
private:
  int addr;
public:
  Float(float f)
  {
    *(fmemory+fmem_top) = f;
    addr = fmem_top++;
  }
  int operator &()
  { return addr; }
};
////////////////////////////////////////
class ptrFloat
{
private:
  int addr;
public:
  ptrFloat(int a)
  { 
    *(pmemory+pmem_top) = a;
    addr = pmem_top++;
  }
  float& operator*()
  {
    return fmemory[pmemory[addr]]; 
  }
};
//////////////////////////////////////
int main()
{
  Float var1 = 1.234; // define and init two Floats
  Float var2 = 5.678;

  ptrFloat ptr1 = &var1; // define two points-to-floats
  ptrFloat ptr2 = &var2; // initialize to addresses of Floats

  cout << " *ptr1=" << *ptr1 << endl; // get values Floats indirectly and display
  cout << " *ptr2=" << *ptr2 << endl;

  *ptr1 = 7.123; // assign new values to variables
  *ptr2 = 8.456; // pointed to by ptr1 and ptr2

  cout << " *ptr1=" << *ptr1 << endl; // get new values indirectly
  cout << " *ptr2=" << *ptr2 << endl; // and display them
  return 0;
}
