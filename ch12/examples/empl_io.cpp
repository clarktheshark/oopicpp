// empl_io.cpp
// performs file I/O on employee objects
// handles different sized obhects
#include <fstream> // for file-stream functions
#include <iostream>
#include <typeinfo> // for typeif()
#include <stdlib.h> // for exit()
using namespace std;

const int LEN = 32; // max length of last name
const int MAXEM = 100; // max number of employees

enum employee_type {tmanager, tscientist, tlaborer};
///////////////////////////////////////////////////////
class employee // employee class
{
private:
  char name[LEN]; // employee name
  unsigned long number; // employee number
  static int n; // current number of employees
  static employee* arrap[]; // array of ptrs to emps
public:
  virtual void getdata()
  {
    cin.ignore(10, '\n');
    cout << "Enter last name: "; cin >> name;
    cout << "Enter number: "; cin >> number;
  }
  virtual void putdata()
  {
    cout << "\nName: " << name;
    cout << "\nNumber: " << number;
  }
  virtual employee_type get_type(); // get type
  static void add(); // add an employee
  static void display(); // display all employees
  static void read(); // read from disk file
  static void write(); // write to disk file
};
//-----------------------------------------------------
int employee::n; // current number of employees
employee* employee::arrap[MAXEM]; // array of ptrs to emps
///////////////////////////////////////////////////////
// manager class
class manager : public employee
{
private:
  char title[LEN]; // "vice-president", etc
  double dues; // golf club dues
public:
  void getdata()
  {
    employee::getdata();
    cout << "Enter title: "; cin >> title;
    cout << "Enter golf club dues: "; cin >> dues;
  }
  void putdata()
  {
    employee::putdata();
    cout << "\nTitle: " << title;
    cout << "\nGolf club dues: " << dues;
  }
};
///////////////////////////////////////////////////////////
// scientist class
class scientist : public employee
{
private:
  int pubs; // number of publications
public:
  void getdata()
  {
    employee::getdata();
    cout << "Enter number of pubs: "; cin >> pubs;
  }
  void putdata()
  {
    employee::putdata();
    cout << "\nNumber of publications: " << pubs;
  }
};
////////////////////////////////////////////////////////////
class laborer : public employee
{
};
///////////////////////////////////////////////////////////
// add employee to list in memory
void employee::add()
{
  char ch;
  cout << "'m' to add a manager"
    "\n's' to add a scientist"
    "\n'l' to add a laborer"
    "\nEnter selection: ";
  cin >> ch;
  switch(ch) // create specified employee type
    {
    case 'm': arrap[n] = new manager; break;
    case 's': arrap[n] = new scientist; break;
    case 'l': arrap[n] = new laborer; break;
    default: cout << "\nUnknown employee type\n"; return;
    }
  arrap[n++]->getdata(); // get employee data from user
}
//-------------------------------------------------------------
// display all employees
void employee::display()
{
  for(int j = 0; j < n; j++)
    {
      cout << (j+1); // display number
      switch( arrap[j]->get_type() ) // display type
	{
	case tmanager: cout << ". Type: Manager"; break;
	case tscientist: cout << ". Type: Scientist"; break;
	case tlaborer: cout << ". Type: Laborer"; break;
	default: cout << ". Unknown type";
	}
      arrap[j]->putdata(); // dispaly employee data
      cout << endl;
    }
}
//--------------------------------------------------------------
// return the type of this object
employee_type employee::get_type()
{
  if( typeid(*this) == typeid(manager) )
    return tmanager;
  else if( typeid(*this) == typeid(scientist) )
    return tscientist;
  else if( typeid(*this) == typeid(laborer) )
    return tlaborer;
  else 
    { cerr << "\nBad employee type"; exit(1); }
  return tmanager;
}
//------------------------------------------------------------------------
// write all current memory objects to file
void employee::write()
{
  int size;
  cout << "Writing " << n << " employees.\n";
  ofstream ouf; // open ofstream in binary
  employee_type etype; // type of each employee object

  ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
  if(!ouf)
    { cout << "\nCan't open file\n"; return; }

  for(int j = 0; j < n; j++) // for every employee object
    {
      etype = arrap[j]->get_type(); // get its type
      ouf.write( (char*)&etype, sizeof(etype) ); // write type to file
      switch(etype)
	{
	case tmanager: size = sizeof(manager); break;
	case tscientist: size = sizeof(scientist); break;
	case tlaborer: size = sizeof(laborer); break;
	}
      ouf.write( (char*)(arrap[j]), size );
      if(!ouf)
	{ cout << "\nCan't write to file\n"; return; }
    }
}
//--------------------------------------------------------------------------------
// read data for all employees from file into memory
void employee::read()
{
  int size; // size of employee object
  employee_type etype; // type of employee
  ifstream inf; // open ifstream in binary
  inf.open("EMPLOY.DAT", ios::binary);
  if(!inf)
    { cout << "\nCan't open file\n"; return; }
  n = 0; // no employees in memory yet
  while(true)
    {
      inf.read( (char*)&etype, sizeof(etype) ); // read the type of employee

      if( inf.eof()) // quit loop on eof
	break;

      switch(etype) // make new employee of correct type
	{
	case tmanager:
	  arrap[n] =  new manager;
	  size = sizeof(manager);
	  break;
	case tscientist:
	  arrap[n] = new scientist;
	  size = sizeof(scientist);
	  break;
	case tlaborer:
	  arrap[n] = new laborer;
	  size = sizeof(laborer);
	  break;
	default: cout << "\nUnknown type in file\n"; return;
	} // read data from file into it
      inf.read( (char*) arrap[n], size );
      if(!inf) // error but not eof
	{ cout << "\nCan't read data from file\n"; return; }
      n++;
    } // end while
  cout << "Reading " << n << " employees\n";
}
///////////////////////////////////////////////////////////
int main()
{
  char ch;
  while(true)
    {
      cout << "'a' -- add data for employee"
	"\n'd' -- display data for all employees"
	"\n'w' -- write all employee data to file"
	"\n'r' -- read all employee data from file"
	"\n'x' -- exit"
	"\nEnter selection: ";
      cin >> ch;
      switch(ch)
	{
	case 'a': // add an employee to list
	  employee::add(); break;
	case 'd': // display all employees
	  employee::display(); break;
	case 'w': // write employees to file
	  employee::write(); break;
	case 'r': // read all employees from file
	  employee::read(); break;
	case 'x': exit(0); // exit program
	default: cout << "\nUnknown command";
	} // end switch
    } // end while
  return 0;
} // end main()
