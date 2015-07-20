// saleinit.cpp
//displays sales chart, initializes 2-d array
#include <iostream>
#include <iomanip> // for setprecision, etc.
using namespace std;

const int DISTRICTS = 4; // array dimensions
const int MONTHS = 3;

int main()
{
  int d, m;

  // init array elements
double sales[DISTRICTS][MONTHS]
  = { { 1, 2, 3 }, 
      { 4, 5, 6 },
      { 7, 8, 9 },
      { 10, 11, 12 } };

 cout << "\n\n";
 cout << "                Month\n";
 cout << "            1    2    3";
 for (d = 0; d < DISTRICTS; d++) 
   {
     cout << "\nDistrict " << d + 1;
     for ( m = 0; m < MONTHS; m++)
       cout << setw(10) << setiosflags(ios::fixed)
	    << setiosflags(ios::showpoint) << setprecision(2)
	    << sales[d][m]; // access array element
   }
 cout << endl;
 return 0;
}
