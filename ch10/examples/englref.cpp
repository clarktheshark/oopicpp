// englref.cpp
// dereferencing the pointer returned by new
#include <iostream>
using namespace std;
///////////////////////////////////////////////
class Distance // English Distance class
{
private:
  int feet;
  float inches;
public:
  void getdist() // get length from user
  {
    cout << "\nEnter feet: "; cin >> feet;
    cout << "Enter inches: "; cin >> inches;
  }
  void showdist() // display distance
  { cout << feet << "\'-" << inches << '\"'; }
};
/////////////////////////////////////////////////
int main()
{
  Distance& dist = *(new Distance); // create Distance object alias is dist access object members with dot operator
  dist.getdist();
  dist.showdist();
  cout << endl;
  return 0;
}
