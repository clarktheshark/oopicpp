// ex_7.cpp
// overloaded power function
#include <iostream>
using namespace std;

double power(double, int);
int power(int, int);
float power(float, int);
char power(char, int);
long power(long, int);

int main()
{
  int p = 2;
  double d1 = 0.25;
  cout << "double: " << power(d1, p) << endl;
  float f1 = 0.5;
  cout << "float: " << power(f1, p) << endl;
  int i1 = 2;
  cout << "int: " << power(i1, p) << endl;
  char c1 = 5;
  cout << "char: " << power(c1, p) << endl;
  long l1 = 10;
  cout << "long: " << power(l1, p) << endl;
  return 0;

}

double power(double n, int p)
{
  double ans = 1;
  for(int i = 0; i < p; i++)
    {
      ans *= n;
    }
  return ans;
}

int power(int n, int p)
{
  int ans = 1;
  for (int i = 0; i < p; i++)
    {
      ans *= n;
    }
  return ans;
}

float power(float n, int p)
{
  float ans = 1;
  for (int i = 0; i < p; i++)
    {
      ans *= n;
    }
  return ans;
}

long power(long n, int p)
{
  long ans = 1;
  for (int i = 0; i < p; i++)
    {
      ans *= n;
    }
  return ans;
}

char power(char n, int p)
{
  char ans = 1;
  for (int i = 0; i < p; i++)
    {
      ans *= n;
    }
  return ans;
}
