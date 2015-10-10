// ex_6.cpp
// reverse int values in vector using 1 forward, 1 reverse iterator
#include <iostream>
#include <vector>
#include <algorithm> // for swap()
using namespace std;

int main()
{
  // declare functions defined below
  void flip(vector<int>&);
  void disp(vector<int>&);
    
  // init 2 vectors, 1 with even number elements, 1 with odd
  vector<int> v1; // size 5, 0..4
  vector<int> v2; // size 6, 0..5
  for(int i = 0; i < 5; i++)
    v1.push_back(i);
  for(int i = 0; i < 6; i++)
    v2.push_back(i);
  
  // disp original vectors
  cout << "\nVector v1, preflip:\n";
  disp(v1);
  cout << "\nVector v2, preflip:\n";
  disp(v2);

  // reverse and display vectors
  flip(v1);
  flip(v2);
  cout << "\n\nVector v1, postflip:\n";
  disp(v1);
  cout << "\nVector v2, postflip:\n";
  disp(v2);
  cout << endl;

  return 0;
}

void flip(vector<int>& v)
{
  vector<int>::iterator fi;
  vector<int>::reverse_iterator ri;
  fi = v.begin();
  ri = v.rbegin();
  while( &(*fi) != &(*ri) )
    {
      swap(*fi, *ri);
      fi++;
      if ( &(*fi) == &(*ri) )
	break;
      ri++;
    }
}

void disp(vector<int>& v)
{
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
}
