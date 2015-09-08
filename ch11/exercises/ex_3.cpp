// ex_3.cpp
#include <iostream>
using namespace std;
////////////////////////////////////////////////
class Array // models a normal C++ array
{
private:
  int* ptr; // pointer to Array contents
  int size; // size of Array
public:
  Array(int s) // one-argument constructor
  {
    size = s;
    ptr = new int[s]; // make space for Array
  }
  Array(Array& A) // overloaded copy constructor
  {
    size = A.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
      { *(ptr+i) = *(A.ptr+i); }
  }
  Array& operator = (Array& A) // assignment operator
  {
    delete[] ptr; // delete old contents
    size = A.size; // copy over size
    ptr = new int[size]; // allot memory for newly sized array
    for (int i = 0; i < A.size; i++) // copy over old data
      { *(ptr+i) = *(A.ptr+i); }
    return *this; // return current object
  }
  ~Array() // destructor
  { delete[] ptr; }
  int& operator[] (int j) // overloaded subscript operator
  { return *(ptr+j); }
  void disp() const
  {
    cout << "Data in: " << ptr << endl;
    for (int i = 0; i < size; i++)
      { cout << *(ptr+i) << " "; }
    cout << endl;
  }
};
///////////////////////////////////////////////
int main()
{
  const int ASIZE = 10; // size of array
  Array arr1(ASIZE); // make an array
  Array arr3(ASIZE);

  // assign values to arrays
  for(int j = 0; j < ASIZE; j++) // fill it with squares
    { arr1[j] = j * j; }

  Array arr2(arr1);
  arr3 = arr1;

  // display all
  arr1.disp();
  arr2.disp();
  arr3.disp();
  return 0;
}
