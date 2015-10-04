// ex_11.cpp
// adding exceptions to String overflow
#include <iostream>
#include <cstring> // for strcpy(), strcat()
#include <stdlib.h> // for exit()
using namespace std;
const int SZ = 4;
/////////////////////////////////////////////////////
class String // user-defined string type
{
private:
  char str[SZ]; // size of Sting Objects
public:
  class StringOverflowEx
  {
  public:
    char loc[80];
    StringOverflowEx(char s[])
    { strcpy(loc, s); }
  };
  String() // constructor, no args
  { strcpy(str, ""); }
  String( char s[] ) // constructor, one arg
  {
    if (strlen(s) < SZ)
      strcpy(str, s);
    else
      {
	throw StringOverflowEx("String::String(char[])");
      }
  }
  void display() const // display the String
  { cout << str; }
  String operator + (String ss) const // add Strings
  {
    String temp; // make a temporary String
    if( strlen(str) + strlen(ss.str) < SZ )
      {
	strcpy(temp.str, str); // copy this string to temp
	strcat(temp.str, ss.str); // add the argument string
      }
    else
      {
	throw StringOverflowEx("String::operator + (String ss)");
      }
    return temp; // return temp String
  }
};
////////////////////////////////////////////////////////
int main()
{
  const int NUMS = 4;
  char* strings[NUMS] = { "Hello", "ab", "a", "Hey" };
  int count = 0;
  for (int i = 0; i < NUMS - 1; i++)
    {
      cout << "\nCount: " << count++;
      try
	{
	  cout << "\ns1: " << strings[i];
	  cout << "\ns2: " << strings[i+1];
	  String s1(strings[i]);
	  String s2(strings[i+1]);
	  String s3;
	  s3 = s1 + s2;
	  cout << "\ns1 + s2: "; s3.display();
	  cout << endl;
	}
      catch(String::StringOverflowEx e)
	{
	  cout << "\nString overflow error in " << e.loc << endl;
	}
    }
  return 0;
}
