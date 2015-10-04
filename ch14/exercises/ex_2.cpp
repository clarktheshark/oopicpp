// ex_2.cpp
// implement template for queue, assuming no EoB operations
#include <iostream>
using namespace std;
const int MAX = 5;
////////////////////////////////////////////////////////////////
template <class T>
class Queue
{
private:
  int head;
  int tail;
  T queue[MAX];
public:
  Queue()
  {
    head = -1;
    tail = -1;
  }
  void push(T);
  T pop();
};
//--------------------------------------------------------------
template <class T>
void Queue<T>::push(T in)
{
  if (tail == MAX - 1)
    tail = -1;
  queue[++tail] = in;
  if (head == -1)
    head = 0;
}
//--------------------------------------------------------------
template <class T>
T Queue<T>::pop()
{
  if (head == MAX)
    head = 0;
  return queue[head++];
}
/////////////////////////////////////////////////////////////////
int main()
{
  Queue<int> qi;
  cout << "\nPushing: 1"; qi.push(1);
  cout << "\nPushing: 2"; qi.push(2);
  cout << "\nPushing: 3"; qi.push(3);
  cout << "\nPushing: 4"; qi.push(4);

  cout << "\nPopping: " << qi.pop();
  cout << "\nPopping: " << qi.pop();
  cout << "\nPopping: " << qi.pop();
  
  cout << "\nPushing: 5"; qi.push(5);
  cout << "\nPushing: 6"; qi.push(6);
  
  cout << "\nPopping: " << qi.pop();
  cout << "\nPopping: " << qi.pop();
  cout << "\nPopping: " << qi.pop();
  cout << endl;

  Queue<char> qc;
  cout << "\nPushing: 'a'"; qc.push('a');
  cout << "\nPushing: 'b'"; qc.push('b');
  cout << "\nPushing: 'c'"; qc.push('c');

  cout << "\nPopping: " << qc.pop();
  cout << "\nPopping: " << qc.pop();
  cout << "\nPopping: " << qc.pop();
  cout << endl;  
  
  return 0;
}
