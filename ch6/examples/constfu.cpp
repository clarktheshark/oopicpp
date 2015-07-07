// constfu.cpp
// demonstrates const member functions
class aClass
{
private:
  int alpha;
public:
  void nonFunc() // non-const member function
  { alpha = 99; } // okay

  void conFunc() const // const member function
  { alpha = 99; } // ERROR: can't modify a member
