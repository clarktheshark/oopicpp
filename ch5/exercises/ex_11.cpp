// ex_11.cpp
// add sterlings
#include <iostream>
using namespace std;

struct sterling {
  int pound;
  int shilling;
  int pence;
};

sterling get_sterling();
sterling add_sterlings(sterling, sterling);
void print_sterling(sterling);

int main()
{
  sterling s1 = get_sterling();
  sterling s2 = get_sterling();
  sterling s3 = add_sterlings(s1, s2);
  cout << endl;
  print_sterling(s1);
  cout << " + " << endl;
  print_sterling(s2);
  cout << " = " << endl;
  print_sterling(s3);
  cout << endl;
  return 0;
}

sterling get_sterling()
{
  sterling s1;
  cout << "Enter pounds: "; cin >> s1.pound;
  cout << "Enter shillings: "; cin >> s1.shilling;
  cout << "Enter pence: "; cin >> s1.pence;
  return s1;
}

sterling add_sterlings(sterling s1, sterling s2)
{
  sterling s3;
  s3.pence = s1.pence + s2.pence;
  if (s3.pence > 11)
    {
      s3.pence -= 12;
      s3.shilling = 1;
    }
  s3.shilling += s1.shilling + s2.shilling;
  if (s3.shilling > 19)
    {
      s3.shilling -= 20;
      s3.pound = 1;
    }
  s3.pound += s1.pound + s2.pound;
  return s3;
}

void print_sterling(sterling s1)
{
  cout << "\u00a3" << s1.pound << "." << s1.shilling << "." << s1.pence;
}
