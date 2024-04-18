#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

struct Job
{
  int id;
  int quantity;
};

int GetNextJob(list<Job>& jobs, int K)
{
  auto it = jobs.begin();

  while (K > 0 && !jobs.empty())
  {
    --(it->quantity);
    
    if (it->quantity <= 0)
    {
      auto next = std::next(it, 1);
      jobs.erase(it);
      it = next;
    }
    else
    {
      ++it;
    }

    if (it == jobs.end())
    {
      it = jobs.begin();
    }

    --K;
  }

  if (jobs.empty())
  {
    return -1;
  }

  return it->id;
}

void q46()
{
  int N, K;
  cin >> N;

  list<Job> jobs;

  for (int i = 0; i < N; ++i)
  {
    int q = 0;
    cin >> q;
    jobs.push_back({ i + 1, q });
  }

  cin >> K;

  int ans = GetNextJob(jobs, K);
  cout << ans;
}