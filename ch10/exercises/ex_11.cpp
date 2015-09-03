// ex_11.cpp
// separate array class
#include <iostream>
#include <stdlib.h>
using namespace std;
const int NUMARRAYS = 10;
const int ARRAYSIZE = 10;
//////////////////////////////////////////
class sa
{
private:
  int* array[NUMARRAYS]; // array of pointers
public:
  sa()
  {
    for (int i = 0; i < NUMARRAYS; i++)
      *(array+i) = new int[ARRAYSIZE];
  }

  void display() const
  {
    for (int i = 0; i < NUMARRAYS; i++)
      {
	for (int j = 0; j < ARRAYSIZE; j++)
	  {
	    cout << *(*(array+i)+j) << " ";
	  }
	cout << endl;
      }
  }
  int& operator [](int n) // note: return by reference
  {
    if ( n >= 0 && n < NUMARRAYS * ARRAYSIZE)
      {
	int i = n / ARRAYSIZE;
	int j = n - ARRAYSIZE * i;
	return *(*(array+i)+j);
      }
    else
      { cout << "Index: " << n << " invalid.\nExiting."; exit(1); }
  }
};
//////////////////////////////////////////////
int main()
{
  sa a;
  
  // populate this jizz from 0 to 990, increments of 10
  for (int i = 0; i < NUMARRAYS; i++)
    for (int j = 0; j < ARRAYSIZE; j++)
      a[i * ARRAYSIZE + j] = 100 * i + 10 * j;

  // print this bitch
  a.display();
  return 0;
}

