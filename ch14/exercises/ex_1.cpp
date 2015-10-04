// ex_1.cpp
// average arrays with templates
#include <iostream>
using namespace std;
const int SIZE = 5;
/////////////////////////////////////////
template <class T>
T average(T* arary, int size)
{
  T ans = 0;
  for (int i = 0; i < size; i++)
    ans += array[i];
  return ans /= size;
}
///////////////////////////////////////////
int main()
{
  int ia[SIZE] = {1, 2, 3, 4, 5};
  long la[SIZE] = {5L, 2L, 3L, 4L, 5L};
  double da[SIZE] = {3.0, 2.0, 3.0, 4.0, 5.0};
  char ca[SIZE] = {'1', '2', '3', '4', '5'};

  cout << "Avg ia: " << average(ia, SIZE) << endl;
  cout << "Avg la: " << average(la, SIZE) << endl;
  cout << "Avg da: " << average(da, SIZE) << endl;
  cout << "Avg ca: " << average(ca, SIZE) << endl;
  return 0;
}
