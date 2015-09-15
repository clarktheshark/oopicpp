// ex_8.cpp
// writing linked list to file. this uses insert changing the head
#include <iostream>
#include <fstream>
#include <stdlib.h> // for exit()
const char NAME[] = "ex_8.dat";
using namespace std;
////////////////////////////////////////////////
struct link // one element of the list
{
  int data; // data item
  link* next; // pointer to next link;
};
////////////////////////////////////////////////
class linklist // a list of links
{
private:
  link* first; // pointer to first link
public:
  linklist() // no-argument constructor
  { first = NULL; } // no first link
  void additem(int d); // add data item (one link)
  void display(); // display all links
  void read(fstream&); // read contents of file to create link list
  void write(fstream&); // write current contents of link list to file
};
//-------------------------------------------------
void linklist::additem(int d) // add data item
{
  link* newlink = new link; // make a new link
  newlink->data = d; // give it data
  newlink->next = first; // it points to next link
  first = newlink; // now first points to this
}
//-------------------------------------------------
void linklist::display() // display all links
{
  link* current = first; // set ptr to first link
  while( current != NULL ) // quit on last link
    {
      cout << current->data << endl; // print data
      current = current->next; // move to next link
    }
}
//--------------------------------------------------
void linklist::read(fstream& f)
{
  int i; // int to hold var
  first = NULL;
  f.clear(); // clear all previous eofs and whatever
  f.seekg(0); // go to head of file
  while ( f.read( (char*)&i, sizeof(int) ) )
    {
      // check for errors reading
      if (!f)
	{ cerr << "Could not read from file\n"; f.close(); exit(1); }
      additem(i);
    }
}
//--------------------------------------------------
void linklist::write(fstream& f)
{
  f.flush(); // flush current stream
  f.clear(); // clear all error bits and whatnot
  link* current = first;
  int i; // in to write
  while(current != NULL)
    {
      i = current->data;
      f.write( (char*)&i, sizeof(int) );
      if (!f)
	{ cerr << "Could not write int: " << i << '\n'; f.close(); exit(1); }
      current = current->next;
    }
}
///////////////////////////////////////////////////
int main()
{
  linklist l;
  char ch;
  int i;
  fstream file;

  // try to open file  & check for errors
  file.open(NAME, ios::app | ios::in | ios::out | ios::binary);
  if (!file)
    { 
      cerr << "Could not open file: " << NAME 
	   << "\nError state = " << file.rdstate()
	   << "\ngood() = " << file.good()
	   << "\neof() = " << file.eof()
	   << "\nfail() = " << file.fail()
	   << "\nbad() = " << file.bad()
	   << '\n';
      file.close();
      exit(1);
    }

  while (true)
    {
      // display program options
      cout << "\n'a' --add link"
	   << "\n'd' --display links"
	   << "\n'w' --write data for all links"
	   << "\n'r' --create linked list from file"
	   << "\n'x' --exit program"
	   << endl;

      cout << "\nEnter choice: "; cin >> ch;
      
      switch(ch)
	{
	case 'a':
	  {
	    cout << "\nEnter int: "; cin >> i;
	    l.additem(i);
	    break;
	  }
	case 'd':
	  { l.display(); break;}
	case 'w':
	  { 
	    file.close();
	    file.open(NAME, ios::trunc | ios::binary | ios::in | ios::out);
	    l.write(file);
	    break; }
	case 'r':
	  { l.read(file); break; }
	case 'x':
	  { file.close(); exit(0); }
	default: 
	  { cout << "Invalid option: " << ch; }
	}
    }
  return 0;
}
