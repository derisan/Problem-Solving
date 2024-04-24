#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void q55()
{
  int N;
  cin >> N;

  vector<int> trains(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> trains[i];
  }

  vector<int> intersection;
  vector<char> operations;
  vector<int> B;

  int nextTrain = 1;

  for (const int train : trains)
  {
    if (intersection.empty())
    {
      operations.push_back('P');
      intersection.push_back(train);
    }
    else
    {
      while (!intersection.empty() && intersection.back() == nextTrain)
      {
        B.push_back(intersection.back());
        operations.push_back('O');
        intersection.pop_back();
        ++nextTrain;
      }

      operations.push_back('P');
      intersection.push_back(train);
    }
  }

  const size_t remain = intersection.size();
  for (int i = 0; i < remain; ++i)
  {
    operations.push_back('O');
  }

  B.insert(B.end(), intersection.rbegin(), intersection.rend());

  bool bPossible = true;

  int start = 1;
  for (const int train : B)
  {
    if (train != start++)
    {
      bPossible = false;
      break;
    }
  }

  if (bPossible)
  {
    for (const char op : operations)
    {
      cout << op;
    }
  }
  else
  {
    cout << "impossible";
  }
}