#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void q4()
{
  //freopen("input.txt", "rt", stdin);

  int n = 0;
  std::cin >> n;

  std::vector<int> ages(n);
  int minAge = INT_MAX;
  int maxAge = INT_MIN;
  for (int i = 0; i < n; ++i)
  {
    std::cin >> ages[i];

    minAge = minAge > ages[i] ? ages[i] : minAge;
    maxAge = maxAge < ages[i] ? ages[i] : maxAge;
  }

  std::cout << maxAge - minAge;
}
