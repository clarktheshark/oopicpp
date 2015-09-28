// vl_app.cpp
// calculates factorials of larger numbers using verylong class
#include "verylong.h" //verylong header file

int main()
{
  unsigned long numb, j;
  verylong fact = 1; // initialize verylong

  cout << "\n\nEnter number: "; 
  cin >> numb; // input a long int

  for(j = numb; j > 0; j--)
    fact = fact * j;
  cout << "Factorial is ";
  fact.putvl();
  cout << endl;
  return 0;
}
