#pragma once

#include <iostream>
using namespace std;

void PrintNum(int num, int exitNum)
{
  if (num > exitNum)
    return;

  cout << num << " ";
  PrintNum(num + 1, exitNum);
}

void q56()
{
  int N;
  cin >> N;

  PrintNum(1, N);
}