// virtbase.cpp
// virtual base classes

class Parent
{
protected:
  int basedata;
};
class Child1 : virtual public Parent // shares copy of Parent
{ };
class Child2 : virtual public Parent // shares copy of Parent
{ };
class Grandchild : public Child1, public Child2
{
public:
  int getdata()
  { return basedata; } // OK: onlt one copy of parent
};
