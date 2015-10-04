// ex_10.cpp
// throwing functions in englerr.cpp
#include <iostream>
#include <string>
#include <cstdlib> // for atoi, atof()
using namespace std;
/////////////////////////////////////////////////////
class Distance
{
private:
  int feet;
  float inches;
public:
  class DistEx
  {
  public:
    string location;
    string reason;
    DistEx(string l, string r)
    { location = l; reason = r; }
  };
  Distance() // constructor (no args)
  { feet = 0; inches = 0.0; }
  Distance(int ft, float in) // constructor (two args)
  {
    if ( ft > 999 || ft < -999 || in < 0.0 || in >= 12.0 )
      throw DistEx("Distance::Distance(int, float)",
		   "Range ft: -999 < ft < 999, Range in: 0.0 <= in < 12.0");
    feet = ft; inches = in;
  }
  void showdist()
  { cout << feet << "\'-" << inches << '\"'; }
  void getdist(); // get length from user
  int isFeet(string);
};
//-----------------------------------------------------
void Distance::getdist() // getlength from user
{
  string instr; // for input string
  cout << "\n\nEnter feet: ";
  cin >> instr; // get feet as a string
  if( isFeet(instr) ) // is it a correct feet value
    feet = stoi(instr); // convert to integer
        
  cout << "Enter inches: ";
  cin >> inches; // get inches (type float)
  if(inches >= 12.0 || inches <0.0)
    throw DistEx("Distance::getdist()", "Inches must be 0.0 <= inches < 12.0");
  if( cin.good() ) // check for cin failure
      return;
  cin.clear(); // error; clear the error state
  throw DistEx("Distance::getdist()", "Incorrect inches input");
}
//------------------------------------------------------------
int Distance::isFeet(string str) // return true if the string
{ // is a correct feet value
  int slen = str.size(); // get length
  if(slen==0 || slen > 5) // if no input or too long
    throw DistEx("Distance::isFeet(string)",
		 "Input string length invalid length");
  for(int j = 0; j < slen; j++) // check each character if not digit or minus
    if( (str[j] < '0' || str[j] > '9') && str[j] != '-' )
      throw DistEx("Distance::isFeet(string)",
		   "Input contains nonnumeric character");
  double n = stod( str); // convert to double
  if( n <-999.0 || n>999.0) // is it out of range?
    throw DistEx("Distance::isFeet(string)",
		 "Feet out of range -999 < feet < 999");
  return 1;
}
///////////////////////////////////////////////////////////
int main()
{
  Distance d; // make a Distance object
  char ans;
  do
    {
      try
	{
	  d.getdist(); // get it's value from user
	  cout << "\nDistance = ";
	  d.showdist(); // display it
	  cout << "\nDo another (y/n)? ";
	  cin >> ans;
	  cin.ignore(10, '\n'); // eat chars, including newline
	}
      catch(Distance::DistEx e)
	{
	  cout << "\nError thrown from function: " << e.location;
	  cout << "\nReason: " << e.reason;
	  cout << "\nTry again";
	  ans = 'y';
	}
    } while(ans != 'n'); // cycle until 'n'
  return 0;
}
