// ex_7.cpp
// static file member
#include <iostream>
#include <fstream>
#include <stdlib.h> // for exit()
using namespace std;
const int MAX = 80;
const char FILENAME[] = "ex_7.txt";
////////////////////////////////////////////////
class person
{
private:
  char first[MAX];
  char last[MAX];
  char middle;
  unsigned long id;
  static fstream file;
public:
  void getdata()
  {
    cout << "\nEnter first: "; cin >> first;
    cout << "Enter middle: "; cin >> middle;
    cout << "Enter last: "; cin >> last;
    cout << "Enter id: "; cin >> id;
  }
  void putdata() const
  {
    cout << "\nName: " << first << ' ' << middle << ' ' << last;
    cout << "\nID: " << id << ' ';
  }
  void write()
  {
    cout << "\nWriting";
    cout << "\nPrewrite Positions:";
    putpositions();
    file << ' ' << id << ' ' << first << ' ' << middle << ' ' << last;
    cout << "\nPostwrite Positions:";
    putpositions();
  }
  void read()
  {
    cout << "\nReading";
    cout << "\nPreread Positions:";
    putpositions();
    if ( file.eof() )
      {
	cout << "\nEnd of file son, whoops";
	cout << "\nGoing back to the beginning";
	file.clear(); // reset eof bits and suchc
	file.seekg(0);
	file.seekp(0);
	putpositions();
      }
    file >> id >> first >> middle >> last;
    cout << "\nPostread Positions:";
    putpositions();
  }
  static void openfile()
  {
    file.open(FILENAME, ios::trunc | ios::in | ios::out);
  }
  static void putpositions()
  { 
    cout << "\ntellg: " << file.tellg();
    cout << "\ntellp: " << file.tellp();
  }
  static void closefile()
  {
    file.close();
  }
  static void findbeg()
  {
    file.seekp(0, ios::beg);
    file.seekg(0, ios::beg);
  } 
  static void findend()
  {
    file.seekp(0, ios::end);
    file.seekg(0, ios::end);
  }
};
//--------------------------------------------------------------
fstream person::file;
///////////////////////////////////////////////////////////////
int main()
{
  person pers;
  char ch = 'x';
  char pch = 'x';
  
  person::openfile();
  while(true)
    {
      cout << "\n'a' --add person"
	   << "\n'r' --read person"
	   << "\n'x' -- exit"
	   << endl;

      cout << "Choice: "; cin >> ch;
      
      switch(ch)
	{
	case 'a':
	  {
	    if (pch != 'a')
	      { person::findend(); }
	    pers.getdata();
	    pers.write();
	    break;
	  }
	case 'r':
	  {
	    if (pch != 'r')
	      { person::findbeg(); }
	    pers.read();
	    pers.putdata();
	    break;
	  }
	case 'x': person::closefile(); exit(0);
	default: cout << "Invalid choice: " << ch;
	}

      pch = ch;
    }
  return 0;
}
