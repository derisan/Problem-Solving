#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <numeric>
#include <list>
using namespace std;

int josephus(list<int>& princes, int K)
{
  auto kill = princes.begin();
  while (princes.size() > 1)
  {
    for (int i = 0; i < K - 1; ++i)
    {
      ++kill;
      if (kill == princes.end())
      {
        kill = princes.begin();
      }
    }

    auto next = std::next(kill, 1);
    if (next == princes.end())
    {
      next = princes.begin();
    }

    princes.erase(kill);
    kill = next;
  }

  return princes.front();
}

void q45()
{
  int N, K;
  cin >> N >> K;

  list<int> princes;
  for (int i = 1; i <= N; ++i)
  {
    princes.push_back(i);
  }

  int ans = josephus(princes, K);
  cout << ans;
}