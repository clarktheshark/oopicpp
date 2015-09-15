// ex_5.cpp
// time class
#include <iostream>
using namespace std;
//////////////////////////////////////////////
class timez
{
private:
  int hours;
  int minutes;
  int seconds;
public:
  timez()
  { hours = 0; minutes = 0; seconds = 0; }
  void get_time()
  { 
    // get hours
    while(true)
      {
	cout << "\nEnter hours: ";
	cin.unsetf(ios::skipws); // don't skip white space
	cin >> hours;
	if (hours >= 24 || hours < 0)
	  { 
	    cout << "Hours must be an int between 0 and 24\n";
	    cin.clear(ios::failbit); // artificiallt set fail bit
	  }
	if (cin.good())
	  {
	    cin.ignore(10, '\n');
	    break;
	  }
	cin.clear();
	cin.ignore(10, '\n'); // eat chars, including newline
	cout << "Incorrect hours\n";
      }
    // get minutes
    while(true)
      {
	cout << "Enter minutes: "; 
	cin.unsetf(ios::skipws);
	cin >> minutes;
	if (minutes >= 60 || minutes < 0)
	  {
	    cout << "Mintues is an int between 0 and 59\n";
	    cin.clear(ios::failbit);
	  }
	if(cin.good())
	  {
	    cin.ignore(10, '\n');
	    break;
	  }
	cin.clear();
	cin.ignore(10, '\n');
	cout << "Incorrect minutes\n";
      }
    // get seconds
    while(true)
      {
	cin.unsetf(ios::skipws);
	cout << "Enter seconds: ";
	cin >> seconds;
	if(seconds < 0 || seconds >= 60)
	  {
	    cout << "Seconds must be int between 0 and 60\n";
	    cin.clear(ios::failbit);
	  }
	if(cin.good())
	  {
	    cin.ignore(10, '\n');
	    break;
	  }
	cin.clear();
	cout << "Incorrect seconds\n";
	cin.ignore(10, '\n');
      }
  }
  void put_time()
  { cout << hours << ':' << minutes << ':' << seconds; }
};
//////////////////////////////////////////////
int main()
{
  timez t1;
  char c;

  do 
    {
      t1.get_time();
      cout << "time = ";
      t1.put_time();
      
      cout << "\nDo another (y/n)? ";
      cin >> c;
      cin.ignore(10, '\n');
    } while (c != 'n');

  return 0;
}
