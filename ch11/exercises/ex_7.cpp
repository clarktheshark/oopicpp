// ex_7.cpp
#include <iostream>
using namespace std;
const int MAX = 100;
////////////////////////////////////////////
class Token
{
public:
  virtual float getNumber() = 0;
  virtual char getOperator() = 0;
  void print()
  { cout << getNumber() << ":" << getOperator(); }
};
/////////////////////////////////////////////////
class Operator : public Token
{
private:
  char oper; // operators +, -, *, /
public:
  Operator(char c) : oper(c)
  { }
  char getOperator()  // gets value
  { return oper; }
  float getNumber()  // dummy function
  { return 0; }
};
////////////////////////////////////////////////
class Number : public Token
{
private:
  float fnum; // the number
public:
  Number(float f) : fnum(f) // constructor sets the value
  { }
  float getNumber()    // get value
  { return fnum; }
  char getOperator()  // dummy function
  { return '0'; }
};
/////////////////////////////////////////////////
class Stack
{
private:
  Token* st[MAX];
  int top;
public:
  Stack()
  { top = -1; }
  void push(Token* t)
  { st[++top] = t; }
  Token* pop()
  { 
    return st[top--]; 
  }
  int gettop()
  { return top; }
  void print()
  { 
    for (int i = 0; i < top; i++)
      { cout << "i: " << i << " = "; st[i]->print(); cout << endl; }
  }
};
//////////////////////////////////////////////////
int main()
{
  Stack s1;
  Operator o1('+');
  Number n1(3.32);

  cout << "Pushing: "; o1.print(); cout << " at address " << &o1 << endl; s1.push(&o1);
  cout << "Pushing: "; n1.print(); cout << " at address " << &n1 << endl; s1.push(&n1);
  
  cout << "Stack: "; s1.print();
  
  cout << "Pop: "; (s1.pop())->print(); cout << endl; 
  cout << "Pop: "; (s1.pop())->print(); cout << endl;
  return 0;
}
