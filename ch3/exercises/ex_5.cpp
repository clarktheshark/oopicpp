// ex_5.cpp
// pyramid of x's
#include <iostream>
#include <iomanip> // setw()
using namespace std;

int main()
{
  int num_rows;
  cout << "Enter number of rows: ";
  cin >> num_rows;
  for (int i = 1; i <= num_rows; i++)
    {
      int xs = i * 2 - 1;
      int spaces = (num_rows * 2 - 1 - xs) / 2;
      //      cout << "i: " << i << endl;
      //      cout << "num spaces: " << spaces << endl;
      //      cout << "num xs: " << xs << endl;
      cout << string(spaces, ' ') << string(xs, 'X') << string(spaces, ' ') << endl;
    }
  return 0;
}
