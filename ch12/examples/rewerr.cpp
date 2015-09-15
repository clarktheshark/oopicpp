// rewerr.cpp
// handles errors during input and output
#include <fstream> // for file streams
#include <iostream>
#include <stdlib.h> // for exit()
using namespace std;

const int MAX = 1000;
int buff[MAX];

int main()
{
  // fill buffer with data
  for(int j = 0; j < MAX; j++)
    buff[j] = j;

  // create output stream
  ofstream os; // create output stream
  os.open("a:edata.dat", ios::trunc | ios::binary);
  if(!os)
    { err << "Could not open output file\n"; exit(1); }

  // write buffer to it
  cout << "Writing...\n";
  os.write( reinterpret_cast<char*>(buff), MAX*sizeof(int) );
  if(!os)
    { cerr << "Could not write to file\n"; exit(1); }
  os.close(); // must close it

  for(int j = 0; j < MAX; j++) // clear buffer
    buff[j] = 0;

  // create input stream
  ifstream is;
  is.open("a:edata.dat", ios::binary);
  if(!is)
    { cerr << "Could not open input file\n"; exit(1); }

  // read file
  cout << "Reading...\n"; 
  is.read( reinterpret_cast<char*>(buff), MAX*sizeof(int) );
  if(!is)
    { cerr << "Could not read from file\n"; exit(1); }

  // check data
  for(int j = 0; j < MAX; j++)
    if( buff[j] != j )
      { cerr << "\nData is incorrect\n"; exit(1); }
  cout << "Data is correct\n";
  return 0;
}
