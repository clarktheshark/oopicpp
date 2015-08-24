// ex_2.cpp
// safe string class
#include <iostream>
#include <string.h> // for strcpy()
using namespace std;
///////////////////////////////
class String
{
protected:
  const static int SZ = 80;
  char str[SZ];
public:
  String()
  { str[0] = '\0'; }
  String( char s[] )
  { strcpy(str,s); }
  void display() const
  { cout << str; }
  operator char*() // conversion operator
  { return str; } // convert String to C-string
};
////////////////////////////
class Pstring : public String
{
public:
  Pstring( char s[] )
  {
    if (strlen(s) > (SZ -1))
      { 
	int i;
	for (i = 0; i < SZ-1; i++)
	  str[i] = s[i];
	str[i] = '\0';
      }
    else
      String(s);
  }
};
////////////////////////////////////
int main()
{
  char ts_1[] = "hello";
  char ts_2[] = "This string will surely exceed the width of the screen, which is what the SZ constant represents.";
  Pstring ps_1(ts_1);
  Pstring ps_2(ts_2);

  cout << "Test string: " << ts_1 << endl;
  ps_1.display();
  cout << endl;

  cout << "Test string: " << ts_2 << endl;
  ps_2.display();
  cout << endl;
  
  return 0;
}
