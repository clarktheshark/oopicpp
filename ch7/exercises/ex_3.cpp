// ex_3.cpp
// english distances
#include <iostream>
using namespace std;

class Distance
{
  int feet;
  float inches;
public:
  Distance(): feet(0), inches(0)
  { }

  Distance(int f, float i): feet(f), inches(i)
  { }

  void getdist()
  {
    cout << "\nEnter feet: "; cin >> feet;
    cout << "Enter inches: "; cin >> inches;
  }

  void setdist(int ft, float i)
  {
    feet = ft; inches = i;
  }

  void showdist()
  {
    cout << feet << "\'-" << inches << '"';
  }

  void div_dist(Distance d2, int divisor)
  {
    float fltfeet = d2.feet + d2.inches / 12.0;
    fltfeet /= divisor;
    feet = int(fltfeet);
    inches = (fltfeet-feet) * 12.0;
  }

  void add_dist(Distance d2)
  {
    inches += d2.inches;
    if (inches >= 12.0) {
      inches -= 12.0;
      feet++;
    }
    feet += d2.feet;
  }
};

int main()
{

  const int MAX_DISTANCES = 100;
  Distance distances[MAX_DISTANCES];

  int num_distances = 0;
  char more_data = 'y';
  do {
    distances[num_distances++].getdist();
    cout << "Enter another distance? (y/n): "; cin >> more_data;
  } while (more_data != 'n' && num_distances < MAX_DISTANCES);

  Distance sum(0, 0.0);
  for (int i = 0; i < num_distances; i++)
    {
      sum.add_dist(distances[i]);
    }
  sum.div_dist(sum, num_distances);
  cout << "Average Distance: ";
  sum.showdist();
  cout << endl;

  return 0;
}
