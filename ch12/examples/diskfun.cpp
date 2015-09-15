// diskfun.cpp
// reads and writes several objects to disk
#include <fstream> // for file streams
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////
class person // class of persons
{
protected:
  char name[80]; // person's name
  int age; // person's age
public:
  void getData() // get person's data
  {
    cout << "\nEnter name: "; cin >> name;
    cout << " Enter age: "; cin >> age;
  }
  void showData() // display peron's data
  {
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
  }
};
/////////////////////////////////////////////////////////////
int main()
{
  char ch;
  person pers; // create a person's object
  fstream file; // create input/output file

  file.open("GROUP.DAT", ios::app | ios::out |
	    ios::in | ios::binary );

  // data from user to file
  do 
    {
      cout << "\nEnter person's data: ";
      pers.getData(); // get one person's data
      //write to file
      file.write( reinterpret_cast<char*>(&pers), sizeof(pers) );
      cout << "Enter another person (y/n)? ";
      cin >> ch;
    } while (ch == 'y'); // quit on 'n'
 
  file.seekg(0); // reset to start of file
  while( file.read( reinterpret_cast<char*>(&pers), sizeof(pers) ) ) // quit on EOF
    {
      cout < "\nPerson:"; // display person
      pers.showData(); // read another person
    }
  cout << endl;
  return 0;
}
