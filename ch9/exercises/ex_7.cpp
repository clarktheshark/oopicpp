// ex_7.cpp
// postfix for counten2
#include <iostream>
using namespace std;
///////////////////////////////////
class Counter
{
protected:
  unsigned int count;
public:
  Counter() : count()
  { }
  Counter(int c) : count(c)
  { }
  unsigned int get_count() const
  { return count; }
  Counter operator ++ ()
  { return Counter(++count); }
};
/////////////////////////////////////////
class CountPost : public Counter
{
public:
  CountPost() : Counter()
  { }
  CountPost(int c) : Counter(c)
  { }
  CountPost operator ++( int )
  { return CountPost(count++); }
  CountPost operator -- ()
  { return CountPost(--count); } 
};
//////////////////////////////////////////
int main()
{
  int orig_count = 5;
  CountPost c(orig_count);
  CountDn c2(0);
  ++c2;
  ++c;
  cout << "Orig count: " << orig_count << endl;
  cout << "New count: " << c.get_count() << endl;
  return 0;
}
