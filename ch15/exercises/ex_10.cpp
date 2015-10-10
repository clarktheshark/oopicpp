// ex_10.cpp
// use copy_backward() algorithm to allow a shift in sequence to the left
// since insert is often in middle, thinking of using list
#include <iostream>
#include <list>
#include <algorithm> // for copy
using namespace std;

int main()
{
  void print_list(list<int>&);
  // init list with 10 numbers
  list<int> l1;
  for(int i = 0; i < 10; i++)
    l1.push_back(i);
  cout << "\nOriginal list:\n";
  print_list(l1);

  int first1;
  int last1;
  int first2;
  
  cout << "\n\nEnter first index to copy: ";
  cin >> first1;
  cout << "Enter last index to copy: ";
  cin >> last1;
  cout << "Enter destination: ";
  cin >> first2;

  list<int>::iterator it1 = l1.begin();
  list<int>::iterator it2 = l1.begin();
  list<int>::iterator it3 = l1.begin();
  advance(it1, first1);
  advance(it2, last1+1);
  advance(it3, first2);
  
  if (first1 > first2)
    {
      advance(it3, (last1-first1+1));
      copy_backward(it1, it2, it3);
    }
  else
    copy(it1, it2, it3);

  cout << "\nModified list:\n";
  print_list(l1);
  cout << endl;
  return 0;
}

void print_list(list<int>& l)
{
  list<int>::iterator li;
  li = l.begin();
  cout << "Size: " << l.size() << "\n";
  while ( li != l.end() )
    cout << *li++ <<  ' ';
}
