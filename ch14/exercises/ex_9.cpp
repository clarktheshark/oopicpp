// ex_8.cpp
// array out of bounds error with stupid index exception
#include <iostream>
using namespace std;
const int LIMIT = 100;
///////////////////////////////////////////////////////
class safearay
{
private:
  int arr[LIMIT];
public:
  class OutOfBoundsEx
  {
  public:
    int oobi;
    int size;
    OutOfBoundsEx(int o, int m)
    { oobi = o; size = m; }
  };
  int& operator [](int n)
  {
    if( n < 0 || n >= LIMIT )
      throw OutOfBoundsEx(n, LIMIT);
    return arr[n];
  }
};
///////////////////////////////////////////////////////
int main()
{
  safearay sa1;
  for(int j = 0; j < LIMIT; j++)
    sa1[j] = j*10;

  int indexarray[3] = {-1, 0, 101};
  for (int i = 0; i < 3; i++)
    {
      try
	{
	  cout << "\nVal at index " << indexarray[i] << ": " << sa1[indexarray[i]];
	}
      catch(safearay::OutOfBoundsEx e)
	{
	  cout << "\nBad index: " << e.oobi << ", array size: " << e.size;
	}
    }
  return 0;
}
