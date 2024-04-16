#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <deque>
using namespace std;

void q39()
{
  int N = 0;
  cin >> N;

  vector<int> first(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> first[i];
  }

  int M = 0;
  cin >> M;
  
  vector<int> second(M);
  for (int i = 0; i < M; ++i)
  {
    cin >> second[i];
  }

  vector<int> sorted;
  sorted.reserve(N + M);

  //merge(first.begin(), first.end(), second.begin(), second.end(), back_inserter(sorted));

  int i = 0, j = 0;
  while (i < N && j < M)
  {
    if (first[i] < second[j])
    {
      sorted.push_back(first[i]);
      ++i;
    }
    else
    {
      sorted.push_back(second[j]);
      ++j;
    }
  }

  if (i == N)
  {
    sorted.insert(sorted.end(), std::next(second.begin(), j), second.end());
  }
  else
  {
    sorted.insert(sorted.end(), std::next(first.begin(), i), first.end());
  }

  for (int num : sorted)
  {
    cout << num << " ";
  }
}