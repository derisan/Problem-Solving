#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void q51()
{
  int H, W;
  cin >> H >> W;

  vector<vector<int>> territory(H + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= H; ++i)
  {
    for (int j = 1; j <= W; ++j)
    {
      cin >> territory[i][j];
    }
  }

  int th, tw;
  cin >> th >> tw;

  vector<vector<int>> dp(H + 1, vector<int>(W + 1, 0));
  for (int row = 1; row <= H; ++row)
  {
    for (int col = 1; col <= W; ++col)
    {
      dp[row][col] = dp[row - 1][col] + dp[row][col - 1] - dp[row - 1][col - 1] + territory[row][col];
    }
  }

  int maxOrangeTrees = 0;
  for (int row = th; row <= H; ++row)
  {
    for (int col = tw; col <= W; ++col)
    {
      int numTrees = dp[row][col] - dp[row - th][col] - dp[row][col - tw] + dp[row - th][col - tw];
      maxOrangeTrees = std::max(maxOrangeTrees, numTrees);
    }
  }

  cout << maxOrangeTrees;
}