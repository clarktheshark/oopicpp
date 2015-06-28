// ex_7.cpp
// compounding interest calculation
#include <iostream>
using namespace std;

int main()
{
  int number_years;
  unsigned long initial_amount;
  double interest_rate;

  cout << "Enter initial amount: ";
  cin >> initial_amount;
  cout << "Enter number of years: ";
  cin >> number_years;
  cout << "Enter interest rate (percent per year): ";
  cin >> interest_rate;

  double sum = initial_amount;
  for (int i = 1; i <= number_years; i++){
    sum += sum * (interest_rate / 100);
  }

  cout << "At the end of " << number_years
       << ", you will have " << sum << " dollars." << endl;
  return 0;
}
