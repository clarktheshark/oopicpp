// ex_4.cpp
// finds the largest number in array
#include <iostream>
using namespace std;

int main()
{
  int index_of_max(int[], int);

  const int MAX = 100;

  int numbers[MAX];
  int index = 0;
  int ans;
  char more_data = 'y';
  do {
    cout << "Enter number: "; cin >> ans;
    numbers[index++] = ans;
    cout << "Enter more data? (y/n): "; cin >> more_data;
  } while (more_data != 'n' && index < MAX);

  int idx_max = index_of_max(numbers, index);
  cout << "Max index: " << idx_max
       << ", element: " << numbers[idx_max] << endl;;

  return 0;
}

int index_of_max(int ary[], int num_elements) {
  int max = ary[0];
  int max_idx = 0;
  int val;

  for (int i = 1; i < num_elements; i++) {
    val = ary[i];
    if (val > max) {
      max = val;
      max_idx = i;
    }
  }
  return max_idx;
}
