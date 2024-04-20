#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void q49()
{
  int N = 0;
  cin >> N;

  vector<int> fronts(N);
  vector<int> rights(N);

  for (int i = 0; i < N; ++i)
  {
    cin >> fronts[i];
  }

  for (int i = 0; i < N; ++i)
  {
    cin >> rights[i];
  }

  reverse(rights.begin(), rights.end());

  vector<vector<int>> blocks(N, vector<int>(N, 0));

  int cnt = 0;
  for (int row = 0; row < N; ++row)
  {
    for (int col = 0; col < N; ++col)
    {
      blocks[row][col] = min(fronts[col], rights[row]);
      cnt += blocks[row][col];
    }
  }

  cout << cnt;
}