// salefunc.cpp
// passes array as argument
#include <iostream>
#include <iomanip> // for setprecision, etc.
using namespace std;

const int DISTRICTS = 4; // array dimensions
const int MONTHS = 3; 
void display( double[DISTRICTS][MONTHS] ); // declaration
//---------------------------------------
int main()
{
double sales[DISTRICTS][MONTHS]
  = { { 1,2,3},
      { 5, 6, 7 },
      { 9, 10, 11 } ,
      {12, 13, 14} };
 display(sales); // call function; array as argument
 cout << endl;
 return 0;
} // end main
//---------------------------------
// display()
// function to display 2-d array passed as argument
void display( double funsales[DISTRICTS][MONTHS] ) 
{
  int d, m;

  cout << "\n\n";
  cout << "            Month\n";
  cout << "            1    2    3";

  for (d = 0; d < DISTRICTS; d++)
    {
      cout << "\nDistrict " << d + 1;
      for (m = 0; m < MONTHS; m++)
	cout << setiosflags(ios::fixed) << setw(10)
	     << setiosflags(ios::showpoint) << setprecision(2)
	     << funsales[d][m]; // array element
    }
}
