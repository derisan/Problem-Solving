#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void q7()
{
  std::string input;
  std::getline(std::cin, input);

  input.erase(std::remove_if(input.begin(), input.end(),
    [](char ch) {
      return std::isspace(ch);
    }), input.end());

  std::transform(input.begin(), input.end(), input.begin(), std::tolower);

  std::cout << input;
}
