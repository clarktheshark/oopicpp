// pubpriv.cpp
// tests publicly and privately-derived classes
#include <iostream>
using namespace std;
/////////////////////////////////////////////////
class A // base class
{
private: 
  int privdataA; // (functions have the same access rules as the members)
protected:
  int protdataA;
public:
  int pubdataA;
};
////////////////////////////////////////////////
class B : public A // publicly-derived class
{
public:
  void funct()
  {
    int a; 
    //    a = privdataA; // error: not accessible
    a = protdataA; // OK
    a = pubdataA; // OK
  }
};
////////////////////////////////////////////////////
class C : private A // privately-derived class
{
public:
  void funct()
  {
    int a;
    //    a = privdataA; // error: not accessible
    a = protdataA; // OK
    a = pubdataA; // OK
  }
};
///////////////////////////////////////////////////////////
int main()
{
  int a;
  B objB;
  // a = objB.privdataA; // error: not accesible
  // a = objB.protdataA; // error: not accesible
  a = objB.pubdataA; // OK (A public to B)
  C Objc;
  // //  A = Objc.privdataA; // error: not accessible
  // //  a = objC.protdataA; // error: not accessible
  // //  a = objC.pubdataA; // error: not accessible (A private to C)
  return 0;
}
