#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

void q40()
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

  sort(first.begin(), first.end());
  sort(second.begin(), second.end());

  vector<int> intersection;
  //set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(intersection));

  int i = 0, j = 0;
  while (i < N && j < M)
  {
    if (first[i] == second[j])
    {
      intersection.push_back(first[i]);
      ++i;
      ++j;
    }
    else if (first[i] < second[j])
    {
      ++i;
    }
    else
    {
      ++j;
    }
  }

  for (int num : intersection)
  {
    cout << num << " ";
  }
}