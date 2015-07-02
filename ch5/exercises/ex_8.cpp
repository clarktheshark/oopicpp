// ex_8.cpp
// interchanges two int values passed by the calling program
#include <iostream>
using namespace std;

void print_values(int, int);
void swap(int&, int&);

int main()
{
  int a = 5, b = 10;
  print_values(a,b);
  swap(a,b);
  print_values(a,b);
  return 0;
}

void print_values(int a, int b)
{
  cout << "A: " << a << ", B: " << b << endl;
}

void swap(int& a, int& b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}
