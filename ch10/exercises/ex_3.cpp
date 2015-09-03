// ex_3.cpp
// sort days of the week into alphabetical order
// instructions are to use bubble sort, so this will be inefficient
#include <iostream>
#include <string.h> // for strcmp
using namespace std;
const int DAYS = 7;

int main()
{

  void bsort(char**, int);
  void display(char**, int);

  char* arrptrs[DAYS] = { "Sunday", "Monday", "Tuesday", 
			  "Wednesday", "Thursday", 
			  "Friday", "Saturday" };
  cout << "\nPre-ordered:\n";
  display(arrptrs, DAYS);
  bsort(arrptrs, DAYS);
  cout << "\nPost-ordered:\n";
  display(arrptrs, DAYS);
  cout << endl;
  return 0;
}
//-----------------------------------------------
void display(char** ca, int n)
{
  for (int i = 0; i < n; i++)
    cout << *(ca+i) << " ";
}
//-------------------------------------------
void bsort(char** ptr, int n)
{
  void order(char**, char**);
  int j, k;

  for(j=0; j < n - 1; j++)
    for (k = j+1; k < n; k++)
      order(ptr+j, ptr+k);
}
//---------------------------------------------
void order(char** s1, char** s2)
{
  if (strcmp(*s1, *s2) > 0)
    {
      char* tempchar = *s1;
      *s1 = *s2;
      *s2 = tempchar;
    }
}
