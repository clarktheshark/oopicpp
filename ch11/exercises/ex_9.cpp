// ex_9.cpp
// copying data from linklist
#include <iostream>
using namespace std;
///////////////////////////////////////////////
struct link // one element of list
{
  int data; // data item
  link* next;
};
////////////////////////////////////////////////
class linklist // a list of links
{
private:
  link* first; // pointer to first link
  link* last; // pointer to tail
public:
  linklist() // no-arg constructor
  { first = NULL; last = NULL; } // no first link
  ~linklist();
  linklist(linklist&); // overloaded copy operator
  linklist& operator = (linklist&); // overloaded assignment operator
  void additem(int d); // add data item (one link)
  void display(); // display all links
};
//------------------------------------------------
linklist::~linklist() // destructor
{
  cout << "entering linklist::~linklist()" << endl;
  link* current = first;
  while ( current != NULL )
    {
      link* tmp = current;
      current = current->next;
      cout << "Deleting node with data: " << tmp->data << endl;
      delete tmp;
    }
  cout << "first: " << first << endl;
  cout << "last: " << last << endl;
  cout << "exiting linklist::~linklist()" << endl;
}
//------------------------------------------------
linklist::linklist(linklist& ll) // overloaded copy operator
{
  cout << "calling overloaded copy operator" << endl;
  first = NULL;
  last = NULL;

  // copy data
  link* current = ll.first;
  while ( current != NULL )
    {
      additem(current->data);
      current = current->next;
    }
}
//--------------------------------------------------
linklist& linklist::operator = (linklist& ll) // overloaded assignment operator
{
  cout << "calling overloaded assignment operator" << endl;
  // delete current old data
  link* current = first;
  while ( current != NULL )
    {
      link* tmp = current;
      current = current->next;
      delete tmp;
    }

  // copy data
  first = NULL;
  last = NULL;
  current = ll.first;
  while ( current != NULL )
    {
      additem(current->data);
      current = current->next;
    }
  return *this;
}
//-------------------------------------------------

void linklist::additem(int d) // add data item
{
  // allot memory for this link and assign it data
  link* newlink = new link;
  newlink->data = d;

  // if no nodes, have both first and last point to this link
  if ( first == NULL)
    { first = newlink; last = newlink; }

  last->next = newlink;
  last = newlink;
  newlink->next = NULL;
}
//------------------------------------------------
void linklist::display() // display all links
{
  cout << "First: " << first << endl;
  cout << "Last: " << last << endl;

  link* current = first; // set ptr to first link
  while ( current !=  NULL ) // quit on last link
    {
      cout << current->data << " at " << current << endl; // print data
      current = current->next; // move to next link
    }
}
/////////////////////////////////////////////////////
int main2()
{
  linklist* lp = new linklist;
  lp->additem(3);
  cout << "linklist address: " << lp;
  delete lp;
  cout << "last command in main\n";
  return 0;
}
/////////////////////////////////////////////////////
int main()
{
  linklist li; // make linked list

  cout << "Adding items to original list" << endl;
  li.additem(25); // add four items to list
  li.additem(36);
  li.additem(49);
  li.additem(64);

  // use overloaded = operator
  linklist li2; // second list
  cout << "Adding items to li2" << endl;
  li2.additem(100); // populate with dummy data to make sure old data is deleted
  li2.additem(200);
  cout << "Using overloaded = operator for statement li2 = li" << endl;
  li2 = li;
  // use copy operator
  cout << "Using copy operator for statement: linklist li3(li)" << endl;
  linklist li3(li);

  // display lists
  cout << "Original list:\n";
  li.display();
  cout << "Deleting original list:\n";
  li2.display();
  cout << "List from copy operator:\n";
  li3.display();
  return 0;
}
