#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool IsCorrect(const string& str)
{
  vector<char> braces;

  for (char ch : str)
  {
    if (ch == '(')
    {
      braces.push_back(ch);
    }
    else if (ch == ')')
    {
      if (braces.empty() || braces.back() == ')')
      {
        return false;
      }

      braces.pop_back();
    }
  }

  if(braces.empty())
  {
    return true;
  }

  return false;
}

void q54()
{
  string chars;
  getline(cin, chars);

  if (IsCorrect(chars))
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }
}