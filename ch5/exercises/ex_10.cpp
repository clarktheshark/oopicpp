// ex_10.cpp
// displays how many times you've been called
#include <iostream>
using namespace std;

int global_count;
void count_local();
void count_global();

int main()
{
  for (int i = 0; i < 10; i++)
    {
      count_local();
      count_global();
    }
  return 0;
}

void count_local()
{
  static float local_count = 0;
  cout << "\nLocal count has been called " << ++local_count << " times";
}

void count_global()
{
  cout << "\nGlobal count has been called " << ++global_count << " times";
}
