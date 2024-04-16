#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool IsPrime(int num)
{
  if (num < 2)
  {
    return false;
  }

  if (num == 2)
  {
    return true;
  }

  if (num % 2 == 0)
  {
    return false;
  }

  for (int i = 3; i * i <= num; i += 2)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}

int GetPrimeFactor(int& outNum)
{
  if (outNum % 2 == 0)
  {
    outNum /= 2;
    return 2;
  }

  for (int i = 3; i <= outNum; ++i)
  {
    if (outNum % i == 0)
    {
      outNum /= i;
      return i;
    }
  }

  return outNum;
}

void q27()
{
  int n = 0;
  cin >> n;

  std::map<int, int> primeFactors;
  primeFactors[2] = 1;

  for (int i = 3; i <= n; ++i)
  {
    const bool bPrimeNumber = IsPrime(i);
    if (bPrimeNumber)
    {
      primeFactors[i] += 1;
    }
    else
    {
      int num = i;
      while (num != 1)
      {
        primeFactors[GetPrimeFactor(num)] += 1;
      }
    }
  }

  cout << n << "! = ";
  for (auto [k, v] : primeFactors)
  {
    cout << v << " ";
  }
}