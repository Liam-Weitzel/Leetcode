#include <string>
#include <utility>
#include <vector>

class Solution { // Nov 03, 2025
public:
  int minCost(std::string colors, std::vector<int> &neededTime) {
    int t = 0;
    int n = colors.size();
    std::pair<char, int> prev = std::make_pair('0', 0);

    for (int i = 0; i < n; i++) {
      if (prev.first == colors[i]) {
        t += std::min(neededTime[i], prev.second);
        prev.second = std::max(neededTime[i], prev.second);
        continue;
      }
      prev = std::make_pair(colors[i], neededTime[i]);
    }

    return t;
  }
};
