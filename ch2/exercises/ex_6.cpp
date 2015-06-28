// ex_6.cpp
// takes dollar amount, gives conversion
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  float dollars;
  int w_cty = 10;
  int w_cry = 15;
  cout << "Enter amount of dollars: ";
  cin >> dollars;
  cout << setw(w_cty) << "Country" << setw(w_cry) << "Conversion" << endl
       << setw(w_cty) << "GB" << setw(w_cry) << dollars / 1.487 << endl
       << setw(w_cty) << "France" << setw(w_cry) << dollars / 0.172 << endl
       << setw(w_cty) << "Germany" << setw(w_cry) << dollars / 0.584 << endl
       << setw(w_cty) << "Japan" << setw(w_cry) << dollars / 0.00955 << endl;
}
