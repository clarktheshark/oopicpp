// ex_5.cpp
// template function for max array element
#include <iostream>
using namespace std;
const int MAX = 5;
///////////////////////////////////////////
template <class T>
T max(T* array, int size)
{
  T max = array[0];
  for (int i = 1; i < size; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
////////////////////////////////////////////
int main()
{
  double ad[MAX] = {5.5, 4.0, 3.0, 2.0, 1.0};
  int ai[MAX] = {5, 6, 1, 2, 3};

  cout << "\nMax ad: " << max(ad, MAX);
  cout << "\nMax ai: " << max(ai, MAX);
  return 0;
}
