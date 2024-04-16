#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

constexpr int MAX_NUM = 1'000'000;
std::array<int, MAX_NUM> nums;

void q42()
{
  int N = 0;
  cin >> N;

  int M = 0;
  cin >> M;

  for (int i = 0; i < N; ++i)
  {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.begin() + N);

  int first = 0;
  int last = (N - 1);
  int mid = 0;

  while (first <= last)
  {
    mid = (first + last) / 2;
    if (nums[mid] == M)
      break;
    
    if (nums[mid] < M)
      first = mid + 1;
    else
      last = mid - 1;
  }

  cout << (mid + 1);
}
