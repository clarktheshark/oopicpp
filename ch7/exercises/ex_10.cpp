// ex_10.cpp
// matrix with max dimensions, with non-intuitive operations for non-applicable indexes

#include <iostream>
using namespace std;

class matrix
{
  static const int MAX = 10;
  int max_x, max_y;
  int data[MAX][MAX];
public:
  matrix(int x, int y)
  { 
    max_x = (x > MAX) ? MAX : x;
    max_y = (y > MAX) ? MAX : y;
  }

  int get_safe_x(int x) {
    return (x > max_x - 1) ? max_x - 1 : x;
  }

  int get_safe_y(int y) {
    return (y > max_y - 1) ? max_y - 1: y;
  }

  void putel(int x, int y, int val)
  {
    x = get_safe_x(x);
    y = get_safe_y(y);
    data[x][y] = val;
  }

  int getel(int x, int y)
  {
    x = get_safe_x(x);
    y = get_safe_y(y);
    return data[x][y];
  }
};

int main()
{
  matrix m1(3, 4);
  int temp = 12345;
  cout << "\nInserting temp: " << temp << endl;
  m1.putel(7, 4, temp);
  temp = m1.getel(7,4);
  cout << "El at 7, 4: " << temp << endl;
}
