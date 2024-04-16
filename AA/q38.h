#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

void q38()
{
  int N = 0;
  cin >> N;

  vector<int> inv(N + 1);
  for (int i = 1; i <= N; ++i)
  {
    cin >> inv[i];
  }

  vector<int> orig(N + 1, 0);

  for (int i = N; i >= 1; --i)
  {
    int temp = i;
    for (int j = 0; j < inv[i]; ++j)
    {
      orig[temp] = orig[temp + 1];
      ++temp;
    }
    orig[temp] = i;
  }

  for (int i = 1; i <= N; ++i)
  {
    cout << orig[i] << " ";
  }
}