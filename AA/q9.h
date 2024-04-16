#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int nums[50001];

void q9()
{
  int n;
  std::cin >> n;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = i; j <= n; j += i)
    {
      ++nums[j];
    }
  }

  for (int i = 1; i <= n; ++i)
  {
    std::cout << nums[i] << " ";
  }
}