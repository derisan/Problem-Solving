#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void q11()
{
  int n = 0;
  std::cin >> n;

  int sum = 0;
  int c = 1;
  int d = 9;
  int res = 0;
  while (sum + d < n)
  {
    res += (c * d);
    sum += d;
    ++c;
    d *= 10;
  }

  res += (n - sum) * c;

  std::cout << res;
}