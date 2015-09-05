// virtpers.cpp
// virtual functions with person class
#include <iostream>
using namespace std;
//////////////////////////////////////////
class person // person class
{
protected:
  char name[40];
public:
  void getName()
  { cout << " Enter name: " ; cin >> name; }
  void putName()
  { cout << "Name is: " << name << endl; }
  virtual void getData() = 0; // pure virtual func
  virtual bool isOutstanding() = 0; // pure virtual func
};
///////////////////////////////////////////
class student : public person // student class
{
private:
  float gpa; // grade point average
public:
  void getData() // get student data from user
  {
    person::getName();
    cout << " Enter student's GPA: "; cin >> gpa;
  }
  bool isOutstanding()
  { return (gpa > 3.5); }
};
/////////////////////////////////////////////
class professor : public person // professor class
{
private:
  int numPubs; // numbers of papers published
public:
  void getData() // get professor data from user
  {
    person::getName();
    cout << " Enter number of professor's publications: ";
    cin >> numPubs;
  }
  bool isOutstanding()
  { return (numPubs > 100); }
};
//////////////////////////////////////////////////
int main()
{
  person* persPtr[100]; // array of pointers to persons
  int n = 0; // number of persons on list
  char choice;

  do {
    cout << "Enter student or professor (s/p): ";
    cin >> choice;

    if(choice == 's')
      persPtr[n] = new student; // put new student in array
    else
      persPtr[n] = new professor; // put new prof in array

    persPtr[n++]->getData(); // get data for person
    cout << " Enter another (y/n)? ";
    cin >> choice;

  } while(choice == 'y');

  for (int j = 0; j < n; j++) // print names of all persons
    {
      persPtr[j]->putName(); // say if outstanding
      if ( persPtr[j]->isOutstanding() )
	cout << " This person is outstanding\n";
    }
  return 0;
}
