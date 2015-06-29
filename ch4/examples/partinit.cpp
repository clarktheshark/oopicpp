// partinit.cpp
// shows initialization of structure variables
#include <iostream>
using namespace std;
////////////////////////////
struct part // specify a structure
{
  int modelnumber; // id number of widget
  int partnumber; // id number of widget part
  float cost; // cost of part
};
//////////////////////////////////
int main()
{
  part part1 = {6244, 373, 217.55 }; // initialize variable
  part part2; // define variable

  cout << "Model " << part1.modelnumber; // display first variable
  cout << ", part " << part1.partnumber;
  cout << ", costs $" << part1.cost << endl;

  part2 = part1; // assign first variable to secod
  cout << "Model " << part2.modelnumber; // display second variable
  cout << ", part " << part2.partnumber;
  cout << ", costs $" << part2.cost << endl;
  return 0;
}
