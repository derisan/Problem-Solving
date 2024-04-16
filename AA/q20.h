#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

enum eWinner
{
  PlayerA,
  PlayerB,
  Draw,
};

eWinner ChecksWhoWin(int a, int b)
{
  if (a == 3 && b == 1)
  {
    return PlayerB;
  }

  if (a == 1 && b == 3)
  {
    return PlayerA;
  }

  if (a > b)
  {
    return PlayerA;
  }

  if (b > a)
  {
    return PlayerB;
  }

  return Draw;
}

std::string WinnerToString(eWinner winner)
{
  switch (winner)
  {
    case PlayerA:
      return "A";
    case PlayerB:
      return "B";
    case Draw:
      return "D";
    default:
      assert(false);
      return "";
  }
}

void q20()
{
  int numGames = 0;
  std::cin >> numGames;

  std::vector<int> aInfos(numGames);
  for (int i = 0; i < numGames; ++i)
  {
    std::cin >> aInfos[i];
  }

  std::vector<int> bInfos(numGames);
  for (int i = 0; i < numGames; ++i)
  {
    std::cin >> bInfos[i];
  }

  for (int i = 0; i < numGames; ++i)
  {
    const eWinner winner = ChecksWhoWin(aInfos[i], bInfos[i]);
    std::cout << WinnerToString(winner);
  }
}