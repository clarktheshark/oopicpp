// ex_3.cpp
// get size of file
#include <iostream>
#include <fstream>
#include <stdlib.h> // for exit()
using namespace std;
///////////////////////////////////////////////
int main(int argc, char* argv[])
{
  // check number args
  if (argc != 2)
    {
      cerr << "Not enough arguments"
	   << "\nUsage: ./a.out <filename>\n"; exit(1);
    }

  // try to open file
  ifstream infile;
  infile.open(argv[1]);
  if (!infile)
    { cerr << "Could not open file: " << argv[1] << "\n"; exit(1); }

  // go to file
  infile.seekg(0, ios::end);
  cout << "Number of bytes in file: " << infile.tellg();
  cout << endl;
  return 0;
}
