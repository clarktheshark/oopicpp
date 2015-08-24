// ex_3.cpp
// adding sales to publication, book, tape
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////
class sales
{
private:
  const static int MONTHS = 3;
  float pastsales[MONTHS];
public:
  void getdata()
  {
    cout << "Enter sales data:\n";
    for (int i = 0; i < MONTHS; i++)
      {
	cout << "Month " << i + 1 << ": "; cin >> pastsales[i];
      }
  }
  void putdata() const
  {
    for (int i = 0; i < MONTHS; i++)
      {
	cout << "\nSales, month " << i + 1 << ": " << pastsales[i];
      }
  }
};
/////////////////////////////////////////////////////
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
////////////////////////////////////////////////
class tape : private publication, private sales
{
private:
  float playtime;
public:
  void getdata()
  {
    publication::getdata();
    sales::getdata();
    cout << "Enter playtime: "; cin >> playtime;
  }
  void putdata() const
  {
    publication::putdata();
    sales::putdata();
    cout << "\nPlaytime: " << playtime;
  }
};
//////////////////////////////////////////////////
class book : private publication, private sales
{
private:
  int pagecount;
public:
  void getdata()
  {
    publication::getdata();
    sales::getdata();
    cout << "Enter pagecount: "; cin >> pagecount;
  }
  void putdata() const
  {
    publication::putdata();
    sales::putdata();
    cout << "\nPage count: " << pagecount;
  }
};
///////////////////////////////////////////////
int main()
{
  book b1;
  tape t1;

  // get data
  cout << "\nEnter tape t1 data:";
  t1.getdata();
  cout << "\nEnter book b1 data:";
  b1.getdata();

  // display data
  cout << "\n\nTape t1:";
  t1.putdata();
  cout << "\n\nBook b1:";
  b1.putdata();

  return 0;
}
