// ex_4.cpp
// four function calculator
#include <iostream>
using namespace std;

int main()
{
  double first_number, second_number, answer;
  char op, option;
  do {
    cout << "Enter first number, operator, second number: ";
    cin >> first_number >> op >> second_number;
    switch(op)
      {
      case '+':
	answer = first_number + second_number;
	break;
      case '-':
	answer = first_number - second_number;
	break;
      case '*':
	answer = first_number * second_number;
	break;
      case '/':
	answer = first_number / second_number;
	break;
      }
    cout << "Answer = " << answer << endl
	 << "Do another (y/n)? ";
    cin >> option;
  } while (option != 'n');
  return 0;
}
