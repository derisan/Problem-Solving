#include <iostream>
#include <array>
using namespace std;

constexpr int NUM_CARDS = 10;

void q21()
{
  std::array<int, NUM_CARDS> a;
  std::array<int, NUM_CARDS> b;


  for (int i = 0; i < NUM_CARDS; ++i)
  {
    std::cin >> a[i];
  }

  for (int i = 0; i < NUM_CARDS; ++i)
  {
    std::cin >> b[i];
  }

  enum eMatchResult
  {
    None,
    WinPlayerA,
    WinPlayerB,
  };

  int aScore{ 0 };
  int bScore{ 0 };
  eMatchResult matchResult{ None };
  for (int i = 0; i < NUM_CARDS; ++i)
  {
    if (a[i] == b[i])
    {
      ++aScore;
      ++bScore;
    }

    else if (a[i] > b[i])
    {
      aScore += 3;
      matchResult = eMatchResult::WinPlayerA;
    }

    else
    {
      bScore += 3;
      matchResult = eMatchResult::WinPlayerB;
    }
  }

  std::cout << aScore << " " << bScore << "\n";

  if (aScore == bScore)
  {
    switch (matchResult)
    {
      case eMatchResult::WinPlayerA: std::cout << "A"; break;
      case eMatchResult::WinPlayerB: std::cout << "B"; break;
      default: std::cout << "D"; break;
    }
  }
  else if (aScore > bScore)
  {
    std::cout << "A";
  }
  else
  {
    std::cout << "B";
  }
}