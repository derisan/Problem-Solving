#include <iostream>
#include <string>
using namespace std;

void q5()
{
  std::string ssn;
  std::cin >> ssn;

  constexpr int CURRENT_YEAR = 2019;
  int age = 0;
  switch (ssn[7])
  {
    case '1':
    case '2':
    {
      const int birthYear = 1900 + (ssn[0] - '0') * 10 + (ssn[1] - '0');
      age = CURRENT_YEAR - birthYear + 1;
    }
      break;

    case '3':
    case '4':
    {
      const int birthYear = 2000 + (ssn[0] - '0') * 10 + (ssn[1] - '0');
      age = CURRENT_YEAR - birthYear + 1;
    }
      break;
  }

  std::cout << age << " " << ((ssn[7] == '1' || ssn[7] == '3') ? 'M' : 'W');
}