// ex_8.cpp
// making arrays safer for the world
#include <iostream>
using namespace std;

class safearay
{
  const static int LIMIT = 100;
  int ary[LIMIT];
public:
  void putel(int index, int value) {
    if (index < 0 || index >= LIMIT) {
      cout << "\nNOT INSERTING element " << value
	   << " at index " << index
	   << " of array size " << LIMIT << endl;
    } else {
      ary[index] = value;
    }
  }

  int getel(int index) {
    if (index < 0 || index >= LIMIT) {
      cout << "\nBAD INDEX " << index
	   << " FOR ARRAY SIZE " << LIMIT << endl;
      return 0;
    } else {
      return ary[index];
    }
  }
};

int main()
{
  safearay sa1;
  int index = -1;
  int temp = 12345;
  sa1.putel(index, temp);
  cout << "Value at index " << index
       << ": " << sa1.getel(index) << endl;
  return 0;
}
