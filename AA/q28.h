#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool IsPrime2(int num)
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

int GetPrimeFactor2(int& outNum)
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

void q28()
{
  int n = 0;
  cin >> n;

  std::map<int, int> primeFactors;
  primeFactors[2] = 1;

  for (int i = 3; i <= n; ++i)
  {
    const bool bPrimeNumber = IsPrime2(i);
    if (bPrimeNumber)
    {
      primeFactors[i] += 1;
    }
    else
    {
      int num = i;
      while (num != 1)
      {
        primeFactors[GetPrimeFactor2(num)] += 1;
      }
    }
  }

  auto it = primeFactors.find(2);
  if (it != primeFactors.end())
  {
    const int numTwos = it->second;

    it = primeFactors.find(5);
    if (it != primeFactors.end())
    {
      const int numFives = it->second;

      cout << std::min(numTwos, numFives);
    }
  }
}