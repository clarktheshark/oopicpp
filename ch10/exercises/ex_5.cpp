// ex_5.cpp
// add arrays index by index
#include <iostream>
using namespace std;

int main()
{
  void addarrays(float*, float*, float*, int);
  void disparray(float*, int);
  const int SIZE = 3;
  float a1[SIZE] = { 0, 2, 4 };
  float a2[SIZE] = { 1, 3, 5 };
  float a3[SIZE];

  addarrays(a1, a2, a3, SIZE);
  cout << endl; disparray(a1, SIZE); cout << " + ";
  cout << endl; disparray(a2, SIZE); cout << " = ";
  cout << endl; disparray(a3, SIZE); cout << endl;
  return 0;
}
//-------------------------------------------------------
void disparray(float* a, const int size)
{
  cout << "[";
  for(int i = 0; i < size; i++)
    {
      cout << *(a+i);
      if (i < size - 1)
	cout << ", ";
    }
  cout << "]";
}
//----------------------------------------------------------
void addarrays(float* a1, float* a2, float* a3, int size)
{
  for(int i = 0; i < size; i++)
    *(a3+i) = *(a1+i) + *(a2+i);
}
