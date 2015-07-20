// ex_7.cpp
// convert money in format $1,234,567.99 to long double
#include <iostream>
#include <stdlib.h> // for strtold()
#include <cstring> // for strlen()
#include <iomanip> // for setprecision, etc
using namespace std;

int main()
{
  long double mstold(char[], int);
  const int MAX = 100;
  // take money and convert
  char more = 'n';
  char value[MAX];
  int count = 0;
  do {
    cout << "Enter money: "; cin >> value;
    cout << "Converted value: "
	 << setiosflags(ios::fixed)
	 << setiosflags(ios::showpoint)
	 << setprecision(2)
	 << mstold(value, MAX) << endl;
    cout << "Enter more money? (y/n): "; cin >> more;
    count++;
  } while (more != 'n' && count < MAX);

  return 0;
}

long double mstold(char ms[], int max_length)
{
  long double ans;
  char convert_string[max_length];
  char current_char;
  int c_index = 0;
  for (int i = 0; i < strlen(ms); i++) {
    current_char = ms[i];
    if (current_char != ',' && current_char != '$') {
      convert_string[c_index++] = current_char;
    }
  }
  convert_string[c_index] = '\0';
  ans = atof(convert_string);
  return ans;
}
