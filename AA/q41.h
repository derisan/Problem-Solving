#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

void q41()
{
  int N = 0;
  cin >> N;

  int cnt = 0;
  for (int i = 2; i < N; ++i)
  {
    int sub = i * (1 + i) / 2; // 1부터 i까지의 합
    if (N >= sub && ((N - sub) % i == 0))
    {
      int perBasket = (N - sub) / i;
      cout << perBasket + 1;
      for (int j = 2; j <= i; ++j)
      {
        cout << " + " << perBasket + j;
      }

      cout << " = " << N << "\n";
      ++cnt;
    }
  }

  cout << cnt;
}