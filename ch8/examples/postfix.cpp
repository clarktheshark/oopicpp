// postfix.cpp
// overloaded ++ operator in both prefix and postfix
#include <iostream>
using namespace std;
/////////////////////////////////////////////////
class Counter
{
private:
  unsigned int count;
public:
  Counter() : count(0) // constructor, no args
  { }
  Counter(int c) : count(c) // constructor, one arg
  { }

  unsigned int get_count() const // return count
  { return count; }

  Counter operator ++ () // increement count(prfix)
  { // increment count, then return
    return Counter(++count); // an unnamed temp object
  } // initialized to this count

  Counter operator ++ (int) // increment count (postfix)
  { // return an unnamed temp
    return Counter(count++); // object init to this
  } // count, then increment count
};
///////////////////////////////
int main()
{
  Counter c1, c2;

  cout << "\nc1 =" << c1.get_count(); // display
  cout << "\nc2 =" << c2.get_count();

  ++c1;
  c2 = ++c1; // c1=2, c2=2 (prefix)

  cout << "\nc1=" << c1.get_count(); // display
  cout << "\nc2=" << c2.get_count();

  c2 = c1++; // c1=3, c2 = 2 (postfix)
  cout << "\nc1=" << c1.get_count(); // display again
  cout << "\nc2=" << c2.get_count() << endl;
  return 0;
}
