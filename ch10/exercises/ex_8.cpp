// ex_8.cpp
// adding link to end of the list, instead of the beginning
#include <iostream>
using namespace std;
////////////////////////////////////////////////////
struct link
{
  int data; // data item
  link* next; // pointer to next link
};
///////////////////////////////////////////////////
class linklist // a list of links
{
private:
  link* first; // pointer to first link
  link* last;
public:
  linklist() // no-argument constuctor
  { first = NULL; last = NULL; } // no first link
  void additem(int d); // add data item (one link)
  void display();
};
//---------------------------------------------
void linklist::additem(int d) // add data item
{
  link* newlink = new link; // make a new link
  newlink->data = d;

  if ( first == NULL)
    {first = newlink; last = newlink; }
  
  last->next = newlink; // change the current last to this link
  newlink->next = NULL;
  last = newlink;
}
//----------------------------------------------
void linklist::display() // display all links
{
  link* current = first; // set ptr to first link
  while( current != NULL ) // quit on last link
    {
      cout << current->data << endl; // print data
      current = current->next; //move to next link
    }
}
//////////////////////////////////////////////////
int main()
{
  linklist li; // make linked list

  li.additem(25); // add four items to list
  li.additem(36);
  li.additem(49);
  li.additem(64);
  li.display(); // display entire list
  return 0;
}
