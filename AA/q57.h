#pragma once

#include <iostream>
using namespace std;

void ConvertTo(int num)
{
  if (num == 1)
  {
    cout << num;
    return;
  }
  
  ConvertTo(num / 2);
  cout << (num % 2);
}

void q57()
{
  int N;
  cin >> N;

  ConvertTo(N);
}