// ex_11.cpp
// copies source file of integers to destination file using stream iterators
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string source;
  string dest;

  cout << "\nEnter source file: ";
  cin >> source;
  cout << "\nEnter destination file: ";
  cin >> dest;

  // open source and dest files
  ifstream sf(source.c_str());
  ofstream df(dest.c_str());
  // make iterators
  ostream_iterator<int> ositer(df, " ");
  istream_iterator<int> isiter(sf);
  istream_iterator<int> eof;

  int value;
  while(isiter != eof)
    {
      // read from source
      value = *isiter++;
      // output to file
      *ositer++ = value;
    }
  return 0;
}
