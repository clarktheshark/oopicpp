// ex_2.cpp
// sort array of words entered by user
// use vector
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
  char choice;
  vector<string> v;
  string ts;
  // collect words
  cout << endl;
  do
    {
      cout << "Enter word: ";
      cin >> ts;
      v.push_back(ts);
      cout << "Enter another(y/n)? ";
      cin >> choice;
    }
  while(choice != 'n');
  
  // display words
  cout << "\nWords, presort:";
  for(int i = 0; i < v.size(); i++)
    cout << "\n" << v[i];

  // sort and display words
  sort(v.begin(), v.end());
  cout << "\n\nWords, postsort:";
  for(int i = 0; i < v.size(); i++)
    cout << "\n" << v[i];
  cout << endl;

  return 0;
}
