#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

void q19()
{
  int numStudents = 0;
  std::cin >> numStudents;

  std::array<int, 100> heights;
  for (int i = 0; i < numStudents; ++i)
  {
    std::cin >> heights[i];
  }

  int numProblematics = 0;
  const auto endIt = std::next(heights.cbegin(), numStudents);
  for (auto it = heights.cbegin(); it != std::prev(endIt); ++it)
  {
    const int curHeight = *it;
    const bool isProblematic = std::all_of(std::next(it), endIt, [curHeight](int height)
      {
        return curHeight > height;
      });

    if (isProblematic)
    {
      ++numProblematics;
    }
  }

  std::cout << numProblematics;
}