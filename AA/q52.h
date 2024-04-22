#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void q52() 
{
  int N;
  cin >> N;

  vector<int> ugly(N + 1);
  ugly[1] = 1;

  int idx2 = 1, idx3 = 1, idx5 = 1;
  int next_ugly_2 = 2, next_ugly_3 = 3, next_ugly_5 = 5;

  for (int i = 2; i <= N; ++i)
  {
    ugly[i] = min(next_ugly_2, min(next_ugly_3, next_ugly_5));

    if (ugly[i] == next_ugly_2) next_ugly_2 = ugly[++idx2] * 2;
    if (ugly[i] == next_ugly_3) next_ugly_3 = ugly[++idx3] * 3;
    if (ugly[i] == next_ugly_5) next_ugly_5 = ugly[++idx5] * 5;
  }

  cout << ugly[N] << endl;
}