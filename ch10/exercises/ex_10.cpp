// ex_10.cpp
// array of arrays to hold disjoint data
#include <iostream>
using namespace std;
const int NUMARRAYS = 10;
const int MAXSIZE = 10;
int main()
{
  int* ap[NUMARRAYS];
  // set data
  for(int j = 0; j < NUMARRAYS; j++)
    {
      *(ap+j) = new int[MAXSIZE];
      for (int k = 0; k < MAXSIZE; k++)
	{
	  *(*(ap+j)+k) = j*100 + k * 10;
	}
    }

  // print data
  for (int j = 0; j < NUMARRAYS; j++)
    {
      for (int k = 0; k < MAXSIZE; k++)
	{ cout << *(*(ap+j)+k) << " "; }
      cout << endl;
    }

  return 0;
}
