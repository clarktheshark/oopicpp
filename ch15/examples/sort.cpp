// sort.cpp
// sorts and array of integers
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 8;
int arr[SIZE] = { 45, 2, 22, -17, 0, -30, 25, 55 };

void print_array(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << ' ';
}

int main()
{
  cout << "\nOriginal Array: ";
  print_array(arr, SIZE);
  sort(arr, arr+8); // sort the numbers
  cout << "\nSorted Array: ";
  print_array(arr, SIZE);
  cout << endl;
  return 0;
}
