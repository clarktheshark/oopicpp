// ezprint.cpp
// demonstrates cimple output to printer
#include <fstream> // for file streams
using namespace std;

int main()
{
  char* s1 = "\nToday's winning number is ";
  int n1 = 17982;

  ofstream outfile; // make a file
  outfile.open("LP1"); // open it for printer
  outfile << s1 << n1 << endl; // send data to printer
  outfile << '\x0C'; // formfeed to eject  page
  return 0;
}
