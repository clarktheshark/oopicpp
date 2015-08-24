// ex_1.cpp
// publication
#include <iostream>
#include <string>
using namespace std;
/////////////////////////////////
class publication
{
private:
  string title;
  float price;
public:
  void getdata() 
  {
    cout << "\nEnter title: "; cin >> title;
    cout << "Enter price: "; cin >> price;
  }
  void putdata() const
  {
    cout << "\nTitle: " << title;
    cout << "\nPrice: " << price;
  }
};
/////////////////////////////////////////
class book : private publication
{
private:
  int pagecount;
public:
  void getdata()
  {
    publication::getdata();
    cout << "Enter page count: "; cin >> pagecount;
  }
  void putdata() const
  {
    publication::putdata();
    cout << "\nPage count: " << pagecount;
  }
};
/////////////////////////////////////////////
class tape : private publication
{
private:
  float playtime;
public:
  void getdata()
  {
    publication::getdata();
    cout << "Enter playtime: "; cin >> playtime;
  }
  void putdata() const
  {
    publication::putdata();
    cout << "\nPlay time: " << playtime;
  }
};
int main()
{
  tape t1;
  book b1;

  // get data
  cout << "Enter tape info: ";
  t1.getdata();

  cout << "Enter book info: ";
  b1.getdata();

  // display data
  cout << "Tape t1: " << endl;
  t1.putdata();
  cout << endl;

  cout << "Book b1: " << endl;
  b1.putdata();
  cout << endl;

  return 0;

}
