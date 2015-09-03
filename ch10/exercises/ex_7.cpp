// persort.cpp
// sorts person objects using array of pointers
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////
class person
{
protected:
  string name;
  float salary;
public:
  void setData() // set name
  {
    cout << "Enter name: "; cin >> name; 
    cout << "Enter salary: "; cin >> salary;
  }
  void printData() // display Name
  {
    cout << endl << "Name: " << name
	 << endl << "Salary: " << salary << endl;
  }
  string getName() // return the name
  { return name; }
  float getSalary()
  { return salary; }
};
/////////////////////////////////////////////////////
int main()
{
  void salsort(person**, int); // prototype
  person* persPtr[100];
  int n = 0;
  char choice;

  do {
    persPtr[n] = new person;
    persPtr[n]->setData();
    n++;
    cout << "Enter another(y/n)? ";
    cin >> choice;
  } while (choice == 'y');

  cout << "\nUnsorted list:";
  for(int j = 0; j < n; j++)
    { persPtr[j]->printData(); }

  salsort(persPtr, n);

  cout << "\nSorted list:";
  for(int j=0; j<n; j++)
    { persPtr[j]->printData(); }
  cout << endl;
  return 0;
}
//-------------------------------------
void salsort(person** pp, int n)
{
  int j, k;

  for(j = 0; j < n - 1; j++)
    for (k = j + 1; k < n; k++)
      {
	if( (*(pp+j))->getSalary() > (*(pp+k))->getSalary() )
	  {
	    person* tempptr = *(pp+j);
	    *(pp+j) = *(pp+k);
	    *(pp+k) = tempptr;
	  }
      }
}
//---------------------------------------
void bsort(person** pp, int n)
{
  void order(person**, person**); // prototype
  int j, k;

  for(j = 0; j < n - 1; j++)
    for (k = j + 1; k < n; k++)
      order(pp+j, pp+k);
}
//---------------------------------------
void order(person** pp1, person** pp2)
{
  if ( (*pp1)->getName() > (*pp1)->getName() )
    {
      person* tempptr = *pp1;
      *pp1 = *pp2;
      *pp2 = tempptr;
    }
}
