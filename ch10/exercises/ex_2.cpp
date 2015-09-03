// ex_2.cpp
// String class that turns everythign to uppercase
#include <iostream>
#include <cstring> // for strlen()
#include <ctype.h> // for toupper()
using namespace std;
/////////////////////////////////////////////////
class String
{
private:
  char* str;
public:
  String(char* s)
  {
    int length = strlen(s);
    str = new char[length+1];
    strcpy(str, s);
  }
  ~String()
  {
    cout << "Deleting str.\n";
    delete[] str;
  }
  void display()
  {
    cout << str << endl;
  }
  void upitpointers();
  void upit();
};
//---------------------------------------------
void String::upit()
{
  for(int i = 0; i < strlen(str); i++) {
    *(str+i) = toupper(*(str+i));
  }
}
void String::upitpointers()
{
  char* s = str;
  while ( *s )
    {
      *s = toupper(*s);
      s++;
    }
}

int main()
{
  String s1 = "hey buddy How you Doings?";
  cout << "\nOriginal string:\n"; s1.display();
  s1.upitpointers();
  cout << "\nUpper string:\n"; s1.display();
  cout << endl;
  return 0;
}
