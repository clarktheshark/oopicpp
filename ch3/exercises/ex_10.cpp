// ex_10.cpp
// calulate years to goal
#include <iostream>
using namespace std;

int main()
{
  double goal_amount, starting_amount, interest_rate;
  cout << "Enter goal amount: ";
  cin >> goal_amount;
  cout << "Enter starting amount: ";
  cin >> starting_amount;
  cout << "Enter interest rate: ";
  cin >> interest_rate;

  double sum = starting_amount;
  int num_years;
  while (sum < goal_amount){
    num_years++;
    sum += (sum * interest_rate / 100);
  }
  cout << "Saving " << goal_amount
       << " starting from " << starting_amount
       << " with interest rate " << interest_rate
       << " will take " << num_years << " years" << endl;
  return 0;
}
