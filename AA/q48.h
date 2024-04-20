#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void q48()
{
  vector<vector<int>> nums(9, vector<int>(9, 0));
  vector<int> avrs(9, 0);

  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      cin >> nums[i][j];
      avrs[i] += nums[i][j];
    }
    avrs[i] = static_cast<int>(round(static_cast<double>(avrs[i]) / 9.0));
  }

  for(int i = 0; i < 9; ++i)
  {
    int average = avrs[i];
    auto mindiff = std::min_element(nums[i].cbegin(), nums[i].cend(), [average](int a, int b)
      {
        int left = abs(average - a);
        int right = abs(average - b);
        
        if (left == right)
        {
          return a > b;
        }
        else
        {
          return left < right;
        }
      });
    cout << average << " " << *mindiff << "\n";
  }
}