// ex_9.cpp
// queue
#include <iostream>
using namespace std;

class queue
{
  const static int MAX = 5;
  int q[MAX];
  int count;
  int head;
  int tail;
public:
  queue()
  {
    count = 0;
    head = 0;
    tail = 0;
  }

  void put(int val) {
    // check for too many elements
    if (count == MAX) {
      cout << "Already at max elements. Rough" << endl;
      return;
    }

    // inset value
    q[tail++] = val;
    count++;

    if (tail == MAX)
      tail = 0;
  }

  int get() {
    if (count == 0) {
      cout << "No elements exist in queue! Sad" << endl;
      return 0;
    }

    // get value
    int ans = q[head++];
    count--;

    if (head == MAX)
      head = 0;

    return ans;
  }

  void display() {
    cout << "[";
    for (int i = 0; i < MAX; i++) {
      cout << q[i];
      if (i != MAX - 1) 
	cout << ", ";
    }
    cout << "]" << endl;
  }
};

int main()
{
  char op;
  int val;
  char more = 'y';
  queue q1;
  do {
    cout << "Enter op: "; cin >> op;
    switch(op)
      {
      case 'g':
	{
	  cout << "Pulling Value: " << q1.get();
	  break;
	}
      case 'p':
	{
	  cout << "Enter value: "; cin >> val;
	  q1.put(val);
	  break;
	}
      }
    cout << endl;
    q1.display();
    cout << "Enter more? (y/n): "; cin >> more;
  } while (more != 'n');
}
