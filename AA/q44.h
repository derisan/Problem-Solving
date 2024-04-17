#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

bool IsPossible(const std::vector<int>& stalls, int distance, int C)
{
  int lastPos = stalls[0];
  int cnt = 1;

  for (int i = 1; i < stalls.size(); ++i)
  {
    if (stalls[i] - lastPos >= distance)
    {
      ++cnt;
      lastPos = stalls[i];
    }
  }

  return cnt >= C;
}

int MaxDistance(const std::vector<int>& stalls, int N, int C)
{
  int left = stalls.front();
  int right = stalls.back() - stalls.front();
  int result = 0;

  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (IsPossible(stalls, mid, C))
    {
      left = mid + 1;
      result = mid;
    }
    else
    {
      right = mid - 1;
    }
  }

  return result;
}

void q44()
{
  int N, C;
  cin >> N >> C;

  vector<int> stalls(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> stalls[i];
  }

  sort(stalls.begin(), stalls.end());

  int answer = MaxDistance(stalls, N, C);
  cout << answer;
}