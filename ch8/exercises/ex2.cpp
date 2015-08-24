// ex2.cpp
// overloads '+='
#include <iostream>
using namespace std;
#include <string.h> // for strcpy(), strcat()
#include <stdlib.h> // for exit()
//////////////////////////////////////
class String // user-defined string type
{
private:
  static const int MAX = 80;
  char str[MAX];
public:
  String()
  { strcpy(str, ""); }
  String( char s[] )
  { strcpy(str, s); }
  void display() const
  { cout << str; }
  String operator + (String ss) const // add Strings
  {
    String temp;
    if (strlen(str) + strlen(ss.str) < MAX ) 
      {
	strcpy(temp.str, str); // copy this string to temp
	strcat(temp.str, ss.str); // add the argument string
      }
      else
	{ cout << "\nString overflow"; exit(1); }
      return temp; // return temp String
  }
  String operator += (String ss)
  {
    if (strlen(str) + strlen(ss.str) > MAX)
      { cout << "\nString overflow"; exit(1); }
    strcat(str, ss.str);
    return String(str);
  }
};
////////////////////////////////////////
int main()
{
  String s1 = "\nMerry Christmas!  "; // uses constructor 2
  String s2 = "Happy new year!"; // uses constructor 2
  String s4 = "Hey ";
  String s5 = "There";
  String s3, s6; // uses constructor 1

  s1.display();
  s2.display();
  s3.display();

  s3 = s1 + s2;
  s3.display();
  cout << endl;
  s4 += s5;
  s4.display();
  cout << endl;
  s6 = s4 += s5;
  s6.display();
  cout << endl;
  s4.display();
  cout << endl;
  return 0;
}
