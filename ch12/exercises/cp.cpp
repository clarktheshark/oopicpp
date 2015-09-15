// ex_2.cpp
// emulate cp command
#include <iostream>
#include <fstream>
#include <stdlib.h> // for exit()
using namespace std;
///////////////////////////////////////////////////
int main(int argc, char* argv[])
{
  // check arg count
  if ( argc != 3)
    {
      cerr << "Incorrect number of arguments"
	   << "\nUsage: ./a.out <file> <file>";
      exit(-1);
    }

  ofstream outfile(argv[2]);
  ifstream infile(argv[1]);

  // check in and out
  if( !infile )
    { cout << "Could not open input file: " << argv[1] << "\n"; exit(1); }
  if( !outfile )
    { cout << "Could not open output file: " << argv[2] << "\n"; exit(1); }

  outfile << infile.rdbuf();

  return 0;
}
