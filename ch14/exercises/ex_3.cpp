// ex_3.cpp
// more robust queue class
#include <iostream>
using namespace std;
const int MAX = 5;
//////////////////////////////////////////////////////////////////
template <class T>
class Queue
{
private:
  T queue[MAX];
  int head;
  int tail;
  int items;
public:
  class BoundsEx
  {
  public:
    BoundsEx(int n, int s)
    { num_items = n; queue_size = s; }
    int queue_size;
    int num_items;
  };
  Queue();
  void push(T);
  T pop();
};
//-----------------------------------------------------------------
template <class T> // no-arg constructor
Queue<T>::Queue()
{
  head = -1;
  tail = -1;
  items = 0;
}
//------------------------------------------------------------------
template <class T>
void Queue<T>::push(T val)
{
  // If there are too many items, throw exception
  if (items == MAX)
    throw BoundsEx(items, MAX);

  // Otherwise, add item to tail
  if (tail == MAX - 1)
    tail = -1;
  queue[++tail] = val;
  items++;
}
//------------------------------------------------------------------
template <class T>
T Queue<T>::pop()
{
  // If there are no items to pop, throw exception
  if (items == 0)
    throw BoundsEx(items, MAX);
  
  // Otherwise, get item
  if (head == MAX - 1)
    head = -1;
  items--;
  return queue[++head];
}
////////////////////////////////////////////////////////////////////
int main()
{
  char ch;
  Queue<int> q;
  int v;
  do
    {
      try
	{
	  cout << "\n'a' for push, 'b' for pop: ";
	  cin >> ch;
	  switch(ch)
	    {
	    case 'a':
	      {
		cout << "Enter int to push: ";
		cin >> v;
		q.push(v);
		break;
	      }
	    case 'b':
	      {
		cout << "Popping value: "
		     << q.pop();
		break;
	      }
	    default:
	      { cout << "Invalid option"; }
	    }
	}
      catch(Queue<int>::BoundsEx e)
	{
	  cout << "\nInvalid queue request"
	       << "\nNum items: " << e.num_items
	       << "\nQueue size: " << e.queue_size;
	}
      cout << "\nEnter another (y/n)? ";
      cin >> ch;
    }
  while (ch != 'n');
  return 0;
}
