#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int digit_sum(int digit)
{
  int sum = 0;

  while (digit > 0)
  {
    int remainder = digit % 10;
    sum += remainder;
    digit /= 10;
  }
  
  return sum;
}

void q10()
{
  int n = 0;
  std::cin >> n;

  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i)
  {
    std::cin >> nums[i];
  }

  int maxDigitSum = INT_MIN;
  int maxNum = INT_MIN;
  for (int num : nums)
  {
    const int digitSum = digit_sum(num);
    if (maxDigitSum < digitSum)
    {
      maxDigitSum = digitSum;
      maxNum = num;
    }
    else if(maxDigitSum == digitSum)
    {
      maxNum = maxNum < num ? num : maxNum;
    }
  }

  std::cout << maxNum;
}