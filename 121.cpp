#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

class Solution { // Jan 15, 2026
public:
  int maxProfit(std::vector<int> prices) {
    if(prices.size() == 1) return 0;

    std::vector<std::pair<int, int>> minMax(prices.size(), std::make_pair(0, 0));

    minMax[0].first = prices[0];
    for (int i = 1; i < prices.size(); i++)
      minMax[i].first = std::min(minMax[i-1].first, prices[i]);

    minMax[prices.size()-1].second = prices[prices.size()-1];
    for (int i = prices.size()-2; i >= 0; i--)
      minMax[i].second = std::max(minMax[i+1].second, prices[i]);

    int res = 0;
    for (std::pair<int, int> i : minMax)
      res = std::max(i.second - i.first, res);
    return res;
  }
};

void testSolution(std::vector<int> prices, int expected) {
  Solution res;
  int ans = res.maxProfit(prices);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "prices: ";
  for(int i : prices) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "ans: " << ans << std::endl;

  std::cout << "expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({7,1,5,3,6,4}, 5);
  testSolution({7,6,4,3,1}, 0);
  testSolution({0}, 0);
  testSolution({1, 2, 3, 4, 5}, 4);
  testSolution({1, 2, 3, 4}, 3);
  testSolution({1, 2, 3}, 2);
  testSolution({1, 2}, 1);
}
