// ex_6.cpp
//
#include <iostream>
#include <fstream>
#include <string.h> // for strlen()
#include <stdlib.h> // for exit()
using namespace std;
const int MAX = 80;
const char* NAME = "ex_6.txt";
//////////////////////////////////////////////////////
class person
{
private:
  char first[MAX];
  char last[MAX];
  char middle;
  unsigned long id;
public:
  void write()
  {
    ofstream outfile;
    outfile.open(NAME, ios::app);
    outfile << id
	    << ' '
	    << first
	    << ' '
	    << middle
	    << ' '
	    << last 
	    << ' ';
    outfile.close();
  }
  void read(unsigned long i)
  {
    ifstream infile;
    infile.open(NAME);
    bool found = false;
    while(infile)
      {
	infile >> id >> first >> middle >> last;
	if (id == i)
	  {
	    found = true;
	    putdata();
	    break;
	  }
      }
    if (!found)
      cout << "Cannot find person with id: " << i << endl;
  }
  void getdata()
  {
    cout << "\nEnter first name: "; cin >> first;
    cout << "Enter middle initial: "; cin >> middle;
    cout << "Enter last name: "; cin >> last;
    cout << "Enter id: "; cin >> id;
  }
  void putdata()
  {
    cout << "\nPerson data:\n";
    cout << "Name: "
	 << first
	 << ' '
	 << middle
	 << ' '
	 << last
	 << endl;
    cout << "ID: " << id;
  }
};
////////////////////////////////////////////////////////
int main()
{
  person pers; // person object to be created
  char ch; // selection
  while(true)
    {
      cout << "\n'a' --add person data to file\n"
	   << "'r' --read currently existing person data\n"
	   << "'x' --exit program\n"
	   << "\nEnter choice: ";
      cin >> ch;
      switch(ch)
	{
	case 'a':
	  {
	    cout << "Enter person data:";
	    pers.getdata();
	    pers.write();
	    break;
	  }
	case 'r':
	  {
	    unsigned long id;
	    cout << "\nEnter id: "; cin >> id;
	    pers.read(id);
	    break;
	  }
	case 'x':
	  exit(0);
	default:
	  cout << "Unrecognized command: " << ch;
	} // end switch
    }
  return 0;
}
