// ex_4.cpp
// adding destructor to linklist
#include <iostream>
using namespace std;
//////////////////////////////////////////
struct link
{
  int data; 
  link* next;
};
//////////////////////////////////////////
class linklist
{
private:
  link* first;
public:
  linklist()
  { first = NULL; }
  ~linklist()
  {
    link* current = first;
    link* nextnode = first;
    while (current != NULL)
      {
	cout << "Deleting node: " << current->data << endl;
	nextnode = current->next;
	delete current;
	current = nextnode;
      }
  }
  void additem(int d); // add data item (one link)
  void display();
};
//-------------------------------------------------
void linklist::additem(int d) // add data item
{
  link* newlink = new link;
  newlink->data = d;
  newlink->next = first;
  first = newlink; // now first points to this
}
//--------------------------------------------------
void linklist::display()
{
  link* current = first;
  while (current != NULL)
    {
      cout << current->data << endl;
      current = current->next;
    }
}
/////////////////////////////////////////////////////
int main()
{
  linklist li; // make linked list

  li.additem(25);
  li.additem(36);
  li.additem(49);
  li.additem(64);
  li.display();
  return 0;
}
