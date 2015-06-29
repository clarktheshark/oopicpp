// ex_6.cpp
// enum printing
#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{
  char employee_letter;
  cout << "Enter employee type (first letter only): ";
  cin >> employee_letter;

  etype e1;
  switch(employee_letter)
    {
    case 'a': e1 = accountant; break;
    case 'l': e1 = laborer; break;
    case 's': e1 = secretary; break;
    case 'm': e1 = manager; break;
    case 'e': e1 = executive; break;
    case 'r': e1 = researcher; break;
    }
  string employee_type;
  switch (e1)
    {
    case accountant: employee_type = "accountant"; break;
    case laborer: employee_type = "laborer"; break;
    case secretary: employee_type = "secretary"; break;
    case manager: employee_type = "manager"; break;
    case executive: employee_type = "executive"; break;
    case researcher: employee_type = "researcher"; break;
    }

  cout << "Employee type is " << employee_type << endl;
  return 0;
}
