// ex_1.cpp
//
#include <iostream>
#include <string>
using namespace std;
/////////////////////////////////////////////////////
class publication
{
private:
  string title;
  float price;
public:
  virtual void getdata()
  {
    cout << "Enter title: "; cin >> title;
    cout << "Enter price: "; cin >> price;
  }
  virtual void putdata()
  {
    cout << "Title: " << title << endl;
    cout << "Price: " << price << endl;
  }
  virtual bool isOversize() = 0;
};
/////////////////////////////////////////////////////
class book : public publication
{
private:
  int pagecount;
public:
  void getdata()
  {
    publication::getdata();
    cout << "Enter page count: "; cin >> pagecount;
  }
  bool isOversize()
  { return ( pagecount > 800 ); }
  void putdata()
  {
    publication::putdata();
    cout << "Page count: " << pagecount << endl;
    if ( isOversize() )
      cout << "Oversize" << endl;
  }
};
///////////////////////////////////////////////////
class tape : public publication
{
private:
  float playingtime;
public:
  void getdata()
  {
    publication::getdata();
    cout << "Enter playing time: "; cin >> playingtime;
  }
  bool isOversize()
  { return ( playingtime > 90 ); }
  void putdata()
  {
    publication::putdata();
    cout << "Playing time: " << playingtime << endl;
    if ( isOversize() ) 
      cout << "Oversize" << endl;
  }
};
/////////////////////////////////////////////////////
int main()
{
  char ans;
  int count = 0;
  const int MAXPUBS = 100;
  publication* pubs[MAXPUBS];

  do 
    {
      cout << "Tape or book (t/b)?: "; cin >> ans;
      if (ans == 'b')
	pubs[count] = new book;
      else
	pubs[count] = new tape;
      pubs[count++]->getdata();

      cout << "Enter more publications (y/n)?: "; cin >> ans;
    } while (count < MAXPUBS && ans != 'n');

  for (int i = 0; i < count; i++)
    {
      pubs[i]->putdata();
    }
  return 0;
}
