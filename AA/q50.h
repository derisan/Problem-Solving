#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void q50()
{
  int H, W;
  cin >> H >> W;

  vector<vector<int>> territory(H, vector<int>(W, 0));

  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> territory[i][j];
    }
  }

  int th, tw;
  cin >> th >> tw;

  int maxSum = 0;
  for (int i = 0; i <= H - th; ++i)
  {
    for (int j = 0; j <= W - tw; ++j)
    {
      int sum = 0;
      for (int k = i; k < i + th; ++k)
      {
        for (int w = j; w < j + tw; ++w)
        {
          sum += territory[k][w];
        }

        maxSum = max(maxSum, sum);
      }
    }
  }

  cout << maxSum;
}