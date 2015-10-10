// ex_4.cpp
// using multiset of pointers to persons
#include <iostream>
#include <string>
#include <algorithm> // for for_each()
#include <set> // for multiset
using namespace std;
/////////////////////////////////////////////////////
class person
{
private:
  string lastName;
  string firstName;
  long phoneNumber;
public:
  person() : // default constrctor
    lastName("blank"), firstName("blank"), phoneNumber(0L)
  { }

  person(string lana, string fina, long pho) :
    lastName(lana), firstName(fina), phoneNumber(pho)
  { }
  friend bool operator<(const person&, const person&);
  friend bool operator==(const person&, const person&);

  void display() const // display person's data
  {
    cout << endl << lastName << ",\t" << firstName
	 << "\t\tPhone: " << phoneNumber;
  }
  long get_phone() const // return phone number
  { return phoneNumber; }
}; // end class person
//--------------------------------------------------------
// overloaded < for person class
bool operator<(const person& p1, const person& p2)
{
  if(p1.lastName == p2.lastName)
    return (p1.firstName < p2.firstName);
  return (p1.lastName < p2.lastName);
}
//----------------------------------------------------------
bool operator==(const person& p1, const person& p2)
{
  return (p1.lastName == p2.lastName &&
	  p1.firstName == p2.firstName);
}
//----------------------------------------------------------
// function object to compare persons using pointers
class comparePersons
{
public:
  bool operator() (const person* ptrP1,
		   const person* ptrP2) const
  { return *ptrP1 < *ptrP2; }
};
//-----------------------------------------------------------
// function object to display a person, using a pointer
class displayPerson
{
public:
  void operator() (const person* ptrP) const
  { ptrP->display(); }
};
/////////////////////////////////////////////////////////////
int main()
{
  multiset< person*, comparePersons > persSet;
  persSet.insert( new person("A", "John", 1111111) );
  persSet.insert( new person("B", "Jane", 2222222) );
  persSet.insert( new person("C", "Adam", 3333333) );
  persSet.insert( new person("A", "John", 4444444) );
  persSet.insert( new person("D", "Jeff", 5555555) );
  persSet.insert( new person("D", "Jane", 6666666) );

  for_each(persSet.begin(), persSet.end(), displayPerson());
  return 0;
}
