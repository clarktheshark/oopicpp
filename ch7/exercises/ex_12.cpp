// ex_12.cpp
// bmoney
#include <iostream> // for cout, cin
#include <iomanip> // for setprecision, etc
#include <cstring> // for strlen()
#include <stdlib.h> // for atof()
#include <sstream> // for ostringstream

using namespace std;

class bMoney
{
  static const int MAX_DIGITS = 20;
  long double money;
public:
  bMoney()
  { } ;

  bMoney(char s[]);

  // convert string to double
  long double mstold(char s[]) {
    long double ans;
    char st[MAX_DIGITS]; // string stripped of $ and ,
    char cur_char;
    int st_index = 0;
    // Build stripped char[]
    for (int i = 0; i < int(strlen(s)); i++) {
      cur_char = s[i];
      if (cur_char != '$' && cur_char != ',') {
	st[st_index++] = cur_char;
      }
    }
    st[st_index] = '\0';
    // convert stripped char[] to number
    ans = atof(st);
    return ans;
  }

  void madd(bMoney m1, bMoney m2){
    money = m1.money + m2.money;
  }

  // get money from user
  void getmoney() {
    char temp[MAX_DIGITS];
    cout << "Enter dollar amount: $"; cin >> temp;
    money = mstold(temp);
  }

  // display money
  void putmoney() {
    ostringstream buffer;
    buffer << setiosflags(ios::fixed)
	   << setiosflags(ios::showpoint)
	   << setprecision(2)
	   << money;
    int str_l = buffer.str().length();
    int num_digits = str_l - 3;
    //    int num_commas = (num_digits - 1) / 3;

    char s[MAX_DIGITS];
    int s_i = 0;
    s[s_i++] = '$';

    for (int i = 0; i < str_l; i++) {
      s[s_i++] = buffer.str().at(i);
      if (!((num_digits - i - 1) % 3) && i < (num_digits - 1)) {
	s[s_i++] = ',';
      }
    }

    s[s_i] = '\0';
    cout << s;
  }
};

int main()
{
  bMoney m1, m2, m3;
  char cont = 'y';
  do {
    // get money
    m1.getmoney();
    m2.getmoney();
    m3.madd(m1,m2);

    // display money
    m1.putmoney();
    cout << " + " << endl;
    m2.putmoney();
    cout << " = " << endl;
    m3.putmoney();
    cout << endl;

    cout << "Enter more money? (y/n): "; cin >> cont;
  } while (cont != 'n');
  return 0;
}
