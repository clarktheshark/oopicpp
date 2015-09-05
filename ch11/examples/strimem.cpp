// strimem.cpp
// memory-saving String class
// overloaded assignment and copy constructor
#include <iostream>
#include <cstring> // for strcpy(), etc.
using namespace std;
/////////////////////////////////////////
class strCount // keep track of number
{
private:
  int count; // number of instance
  char* str; // pointer to string
  friend class Sg; // make ourselves available
  // member functions are private
  //---------------------------------------------
  strCount(char* s) // one-arg constructor
  {
    int length = strlen(s); // length of string argument
    str = new char[length+1]; // get memory for string
    strcpy(str, s); // copy argument to it
    count = 1; // start count at 1
  }
  ~strCount() // destructor
  { delete[] str; } // delete the string
};
/////////////////////////////////////////
class Sg // String class
{
private:
  strCount* psc; // pointer to strCount
public:
  Sg() // no-arg constructor
  { psc = new strCount("NULL"); }
  //------------------------------------------
  Sg(char* s) // 1-arg constructor
  { psc = new strCount(s); }
  Sg(Sg& S) // copy constructor
  {
    psc = S.psc;
    (psc->count)++;
  }
  //------------------------------------------
  ~Sg() // destructor
  {
    if (psc->count == 1) // if we are its last user,
      delete psc; // delete our strCount
    else // otherwise
      (psc->count)--; // decrement
  }
  //-------------------------------------------
  void display() // display the String
  {
    cout << psc->str; // print string 
    cout << " (addr=" << psc << ")"; // print address
  }
  //-------------------------------------------
  void operator = (Sg& S) // assign the string 
  {
    if(psc->count==1) // if we are its last user,
      delete psc; // delete our strCount
    else // otherwise
      (psc->count)--; // descrement its count
    psc = S.psc; // use argument's strCount
    (psc->count)++; // increment its count
  }
};
////////////////////////////////////////////////
int main()
{
  Sg s3("When the fox preaches, look to your geese.");
  cout << "\ns3=";  s3.display(); // display s3

  Sg s1; // define STring
  s1 = s3; // assign it another STring
  cout << "\ns1="; s1.display(); // diplay it

  Sg s2(s3); // initialize with String
  cout << "\ns2="; s2.display(); // display it
  cout << endl;
  return 0;
}
