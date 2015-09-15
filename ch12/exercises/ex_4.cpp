// ex_4.cpp
// read and write person data
#include <iostream>
#include <fstream> // for streams
#include <stdlib.h> // for exit()
using namespace std;
const int MAX = 80;
//////////////////////////////////////////////
int main()
{
  char first[MAX], last[MAX];
  char middle, c;
  unsigned int id;
  char* fn = "ex_4.txt";

  ofstream outfile;
  outfile.open(fn);
  if (!outfile)
    { cerr << "Could not open file: " << fn << "\n"; exit(1); }
  
  // get person information
  do
    {
      cout << "\nEnter person info\n";
      cout << "First: "; cin >> first;
      cout << "Middle: "; cin >> middle;
      cout << "Last: "; cin >> last;
      cout << "ID: "; cin >> id;

      outfile << first
	      << ' '
	      << middle
	      << ' '
	      << last
	      << ' '
	      << id;
      cout << "\nEnter another (y/n)?: ";
      cin >> c;
    } while(c != 'n');

  outfile.close();
  
  // open file
  ifstream infile;
  infile.open(fn);
  if (!infile)
    { cerr << "Could not open file: " << fn << "\n"; exit(1); }
  
  int count = 1;
  infile >> first >> middle >> last >> id;
  while (infile)
    {
      cout << "\nPerson " << count++ << endl
	   << "First: " << first << endl
	   << "Middle: " << middle << endl
	   << "Last: " << last << endl
	   << "ID: " << id << endl;
      infile >> first >> middle >> last >> id;
    }
  infile.close();

  return 0;
}
