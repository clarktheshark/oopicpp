// ex_12.cpp
// four function calculator for fractions
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  char e,f,op,cont;
  int a,b,c,d;
  do {
    cout << "Enter first fraction: ";
    cin >> a >> e >> b;
    cout << "Enter operator: ";
    cin >> op;
    cout << "Enter second fraction: ";
    cin >> c >> f >> d;

    double answer;
    switch(op)
      {
      case '+':
	answer = (a * d + b * c) / (b * d);
	break;
      case '-':
	answer = (a * d - b * c) / (b * d);
	break;
      case '*':
	answer = (a * c) / (b * d);
	  break;
      case '/':
	answer = (a * d) / (b * c);
	break;
      }

    cout << "Answer = " << answer << endl;
    cout << "Repeat?: ";
    cin >> cont;
  } while (cont != 'n');
}
