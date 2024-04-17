#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

void q43()
{
  int N, M;
  cin >> N >> M;

  std::vector<int> songs(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> songs[i];
  }

  int sumSongs = accumulate(songs.begin(), songs.end(), 0);

  int minCapacity = INT_MAX;

  int first = 1;
  int last = sumSongs;
  int mid = 0;

  while (first <= last)
  {
    mid = (first + last) / 2;
    int numDisks = 0;
    int partialSum = 0;
    for (int i = 0; i < N; ++i)
    {
      int t = partialSum + songs[i];

      if (t > mid)
      {
        partialSum = songs[i];
        ++numDisks;
      }
      else if(t < mid)
      {
        partialSum += songs[i];
      }
      else
      {
        partialSum = 0;
        ++numDisks;
      }
    }
    
    if (partialSum > 0)
    {
      ++numDisks;
    }

    if (numDisks <= M)
    {
      minCapacity = std::min(minCapacity, mid);
      last = mid - 1;
    }
    else
    {
      first = mid + 1;
    }
  }

  cout << minCapacity;
}