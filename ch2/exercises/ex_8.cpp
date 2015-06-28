// ex_8.cpp
// change fill from spaces to periods
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  cout << setw(8) << "Portcity" << setw(10) << setfill('.') << 2425787 << endl;
  return 0;
}
