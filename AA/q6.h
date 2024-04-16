#pragma once

#include <iostream>
#include <string>

void q6()
{
  using namespace std;

  std::string input;
  std::cin >> input;

  input.erase(std::remove_if(input.begin(), input.end(),
    [](char ch) {
      return !std::isdigit(ch);
    }), input.end());

  const int number = std::stoi(input);

  int numDivisor = 2; // 자기자신 및 1
  for (int i = 2; i <= (number / 2); ++i)
  {
    if (number % i == 0)
    {
      ++numDivisor;
    }
  }

  std::cout << number << '\n' << numDivisor;
}