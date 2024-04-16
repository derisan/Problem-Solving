#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void q8()
{
  std::string input;
  input.reserve(31);
  std::cin >> input;

  std::stack<char> myStack;
  myStack.push(input.front());

  for (size_t i = 1; i < input.size(); ++i)
  {
    if (myStack.empty())
    {
      myStack.push(input[i]);
      continue;
    }

    const char top = myStack.top();
    if (top == '(' && input[i] == ')')
    {
      myStack.pop();
    }
    else
    {
      myStack.push(input[i]);
    }
  }

  myStack.empty()
    ? std::cout << "YES"
    : std::cout << "NO";
}