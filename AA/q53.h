#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void q53()
{
  int N, K;
  cin >> N >> K;

  std::vector<int> mods;

  while (N >= 1)
  {
    int mod = N % K;
    mods.push_back(mod);
    N /= K;
  }

  for (auto it = rbegin(mods); it != rend(mods); ++it)
  {
    if (*it >= 10)
    {
      cout << static_cast<char>('A' + *it - 10);
    }
    else
    {
      cout << *it;
    }
  }
}