// constObj.cpp
// constant Distance objects
#include <iostream>
using namespace std;
///////////////////////////////////////////
class Distance // English Distance class
{
private:
  int feet;
  float inches;
public:
  // 2-arg constructor
  Distance(int ft, float in) : feet(ft), inches(in)
  { }
  // user input; non-const func
  void getdist()
  { 
    cout << "\nEnter feet: "; cin >> feet;
    cout << "Enter inches: "; cin >> inches;
  }
  void showdist() const // display distance; const func
  { cout << feet << "\'-" << inches << '\"'; }
};
////////////////////////////////////////////////////
int main()
{
  const Distance football(300, 0);
  // football.getdist(); // ERROR: getdist() not const
  cout << "football = ";
  football.showdist(); // OK
  cout << endl;
  return 0;
}
