#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int Solve(const vector<vector<int>>& grid)
{
  int cnt = 0;
  const size_t side = grid.size() - 2;
  for (int i = 1; i <= side; ++i)
  {
    for (int j = 1; j <= side; ++j)
    {
      int target = grid[i][j];

      if (target > grid[i + 1][j] && target > grid[i - 1][j]
        && target > grid[i][j + 1] && target > grid[i][j - 1])
      {
        ++cnt;
      }
    }
  }

  return cnt;
}

void q47()
{
  int N = 0;
  cin >> N;

  vector<vector<int>> grid(N + 2, vector<int>(N+2, 0));

  for (int i = 1; i <= N; ++i)
  {
    for (int j = 1; j <= N; ++j)
    {
      cin >> grid[i][j];
    }
  }

  int ans = Solve(grid);
  cout << ans;
}