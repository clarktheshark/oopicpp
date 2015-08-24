// ex_4.cpp
// addition of disktype
#include <iostream>
#include <string>
using namespace std;

enum disktype { cd, dvd };
/////////////////////////////////////
class publication
{
private:
  string name;
  float cost;
public:
  void getdata()
  {
    cout << "\nEnter name: "; cin >> name;
    cout << "Enter cost: "; cin >> cost;
  }
  void putdata() const
  {
    cout << "\nName: " << name;
    cout << "\nCost: " << cost;
  }
};
////////////////////////////////////
class disk : private publication
{
private:
  disktype d;
public:
  void getdata()
  {
    publication::getdata();
    char dt;
    cout << "Enter disktype (c, d): "; cin >> dt;
    switch (dt)
      {
      case 'c':
	d = cd;
	break;
      case 'd':
	d = dvd;
	break;
      default:
	cout << "Invalid disk type. Sorry bud";
	break;
      }
  }
  void putdata()
  {
    publication::putdata();
    cout << "\nDisktype: ";
    switch (d)
      {
      case cd: cout << "CD"; break;
      case dvd: cout << "DVD"; break;
      }
    cout << endl;
  }
};
/////////////////////////////////
int main()
{
  disk d1;
  cout << "\nEnter disk d1 data: ";
  d1.getdata();

  cout << "\nDisk d1 data:";
  d1.putdata();
  return 0;
}
