// ex_8.cpp
// move elements from to left on array
#include <iostream>
#include <algorithm> // for copy()
using namespace std;

int main()
{
  void print_array(int[], int);
  const int SIZE = 10;
  // init array
  int a[SIZE];
  for(int i = 0; i < SIZE; i++)
    a[i] = i;
  cout << "\nOriginal Array:\n";
  print_array(a, SIZE);
  cout << endl;
  
  int first1;
  int last1;
  int first2;
  cout << "\nEnter first index to move: ";
  cin >> first1;
  cout << "Enter last index to move: ";
  cin >> last1;
  cout << "Enter index to move to: ";
  cin >> first2;
  
  copy(a+first1, a+last1+1, a+first2);
  cout << "\nModified array:\n";
  print_array(a, SIZE);
  cout << endl;
  return 0;
}

void print_array(int a[], int size)
{
  for (int i = 0; i < size; i++)
    cout << a[i] << ' ';
}
