// ex_3.cpp
// takes list of ints, swap values in list
// cannot use reverse iterators
#include <iostream>
#include <list>
using namespace std;

int main()
{
  
  // declare functions
  void print_list(list<int>&);
  void flip(list<int>&);
  
  // init lists with even and odd numbers of values
  int a1[] = { 1, 2, 3, 4, 5 }; 
  int a2[] = { 1, 2, 3, 4, 5, 6};
  list<int> l1(a1, a1+5);
  list<int> l2(a2, a2+6);

  // print original lists
  cout << "\nL1, preflip:\n";
  print_list(l1);
  cout << "\nL2, preflip:\n";
  print_list(l2);

  // flip and print
  flip(l1);
  flip(l2);
  cout << "\n\nL1, postflip:\n";
  print_list(l1);
  cout << "\nL2, postflip:\n";
  print_list(l2);
  return 0;
}

void print_list(list<int>& l)
{
  list<int>::iterator it;
  for(it = l.begin(); it != l.end(); it++)
    cout << *it << ' ';
}

void flip(list<int>& l)
{
  list<int>::iterator it1;
  list<int>::iterator it2;
  it1 = l.begin();
  it2 = l.end(); 
  it2--; // now points to last member
  while(it1 != it2)
    {
      swap(*it1, *it2);
      it1++;
      if (it1 == it2)
	break;
      it2--;
    }
}
