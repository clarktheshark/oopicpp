// ex_1.cpp
// reverses string
#include <iostream>
#include <cstring> // for strlen
using namespace std;

void reversit(char str[])
{
  int len = strlen(str);
  cout << "len: " << len << endl;
  for (int j = 0; j < len / 2; j++)
    {
      //      cout << "j: " << j << ", len - j: " << len - j << endl;
      //      cout << "str[j]: " << str[j] << endl;
      //      cout << "str[len - j]: " << str[len - j] << endl;
      char temp = str[j];
      str[j] = str[len - 1 - j];
      str[len - 1 - j] = temp;
    }
}

int main()
{
  const int MAX = 80;
  char str[MAX];
  cout << "\nEnter string:\n";
  cin.get(str, MAX);
  reversit(str);
  cout << "Reversed String:\n" << str << endl;

  return 0;
}
