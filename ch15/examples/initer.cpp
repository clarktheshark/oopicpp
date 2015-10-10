//  initer.cpp
// demonstrates istream_iterator
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
  list<float> fList(5); // unititialized list

  cout << "\nEnter 5 floating-point numbers: ";

  istream_iterator<float> cin_iter(cin); // cin
  istream_iterator<float> end_of_stream; // eos, note: in unix this is ctrl+d

  copy( cin_iter, end_of_stream, fList.begin() );

  cout << endl;

  ostream_iterator<float> ositer(cout, ", ");

  copy(fList.begin(), fList.end(), ositer);
  cout << endl;
  return 0;
}
