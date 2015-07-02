// extern.cpp
// demonstrates global variables
#include <iostream>
using namespace std;

char ch = 'a'; // global variable ch

void getachar(); // function declarations
void putachar(); 

int main()
{
  while ( ch != '\r' )
