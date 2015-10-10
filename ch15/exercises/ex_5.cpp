// ex_5.cpp
// array of even numbers, set with odd numbers, merge the 2 into vector
#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // for merge
using namespace std;

int main()
{
  // init array and set
  const int SIZE = 5;
  // odd numbers
  cout << "\nInitializing Array";
  int a[SIZE];
  for(int i = 0; i < SIZE; i++)
    a[i] = 2 + 2*i;
  // even numbers
  cout << "\nInitializing Set";
  set<int, less<int> > s;
  cout << "\nsize s: " << s.size();
  for(int i = 0; i < SIZE; i++)
    {
      cout << "\ni: " << i;
      s.insert(1 + 2*i);
    }
  cout << "\nsize s: " << s.size();

  // merge into vector and print
  cout << "\nMerging Into Vector";
  vector<int> v(2*SIZE);
  merge(a, a+SIZE, s.begin(), s.end(), v.begin());
    
  // print array
  cout << "\nA:\n";
  for(int i = 0; i < SIZE; i++)
    cout << a[i] << ' ';
  // print set
  cout << "\nS:\n";
  set<int>::iterator sit;
  for(sit = s.begin(); sit != s.end(); sit++)
    cout << *sit << ' ' ;
  // print vector
  cout << "\nV:\n";
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
  return 0;
}
