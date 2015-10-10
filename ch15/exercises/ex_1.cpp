// ex_1.cpp
// write a program that applies sort() to array of floating points
// numbers are entered by user, and result is displayed
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 5;

int main()
{
  void disp_array(float[], int);

  float floats[MAX];
  char choice;
  int idx = 0;

  cout << endl;
  do
    {
      cout << "Enter float: ";
      cin >> floats[idx++];
      cout << "Enter another(y/n)? ";
      cin >> choice;
    }
  while (choice != 'n' && idx < MAX);  

  // display raw array
  cout << "\nArray, presort:\n";
  disp_array(floats, MAX);
  
  // sort and display array
  sort(floats, floats+MAX);
  cout << "\nArray, postsort:\n";
  disp_array(floats, MAX);
  cout << endl;
  return 0;
}

void disp_array(float fa[], int size)
{
  for (int i = 0; i < size; i++)
    cout << fa[i] << ' ';
}
