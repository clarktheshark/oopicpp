// ex_9.cpp
// shows function binding to find string in container
#include <iostream>
#include <string>
#include <algorithm> // for find_if()
using namespace std;

int main()
{
  void print_array(string[], int);

  const int SIZE = 5;
  string s[] = { "A", "a", "B", "b", "Ab" };
  string* sp;
  
  cout << "\nString Array:\n";
  print_array(s, SIZE);

  string searchString;
  cout << "\nEnter string to find: ";
  cin >> searchString;

  sp = find_if(s, s+SIZE, 
	       bind2nd(equal_to<string>(), searchString));
  
  cout << endl;
  if (sp == s+SIZE)
    cout << '\'' << searchString << '\'' << " NOT found in array";
  else
    cout << '\'' << searchString << '\'' << " found at index " << sp - s;

  cout << endl;
  
  return 0;
}

void print_array(string s[], int size)
{
  for(int i = 0; i < size; i++)
    cout << s[i] << ' ';
}
