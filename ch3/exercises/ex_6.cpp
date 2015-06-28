// ex_6.cpp
// repeatedly calculates factorial
#include <iostream>
using namespace std;

int main()
{
  int number;
  while (1){
    cout << "Enter number for factorial: ";
    cin >> number;
    if (number == 0)
      break;
    unsigned long answer = 1;
    for (int j = number; j > 1; j--) {
      answer *= j;
    }
    cout << "Factorial: " << answer << endl;
  }
  return 0;
}
