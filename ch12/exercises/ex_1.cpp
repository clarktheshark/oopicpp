// englcon.cpp
// constructors, add objects using member functions
#include <iostream>
#include <fstream>
using namespace std;
/////////////////////////////////////////////////
class Distance
{
private:
  int feet;
  float inches;
public:
  Distance() : feet(0), inches(0.0)
  { }
  Distance(int ft, float in) : feet(ft), inches(in)
  { }
  void getdist() // get length from user
  {
    cout << "\nEnter feet: "; cin >> feet;
    cout << "\nEnter inches: "; cin >> inches;
  }
  void showdist() // display distance
  { cout << feet << "\'-" << inches << '\"'; }
  void add_dist(Distance, Distance); // declaration
};
//----------------------------------------------------
// add lengths d2 and d3
void Distance::add_dist(Distance d2, Distance d3)
{
  inches = d2.inches + d3.inches; // add the inches
  feet = 0; // for possible carry
  if(inches >= 12.0) // if total exceeds 12.0
    { // then decrease inches
      inches -= 12.0; // by 12.0 and 
      feet++; // increase feet by 1
    }
  feet += d2.feet + d3.feet; // add the feet
}
////////////////////////////////////////////////////
int main()
{
  Distance d1;
  char ch;
  fstream file("ex_1.dat",
	       ios::app | ios::in | ios::out | ios::binary);

  // get info
  do
  {
    cout << "\nEnter distance information";
    d1.getdist();
    file.write( (char*)&d1, sizeof(d1) );
    cout << "Enter another distance (y/n)?: ";
    cin >> ch;
  } while ( ch != 'n' );

  // print info
  file.seekg(0); // go back to beginning of file
  
  file.read( (char*)&d1, sizeof(d1) );
  while( !file.eof() ) // quit on EOF
    {
      cout << "\nDistance: "; // display distance
      d1.showdist();
      file.read( (char*)&d1, sizeof(d1) );
    }
  cout << endl;

  return 0;
}
