#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

class Solution { // Oct 08, 2025
public:
  std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
    std::sort(potions.begin(), potions.end());

    std::vector<int> res;
    for(int spell : spells) {
      long k = ceil((double)success/(double)spell);
      auto it = std::lower_bound(potions.begin(), potions.end(), k);
      int i = std::distance(potions.begin(), it);
      res.push_back(potions.size()-i);
    }

    return res;
  }
};
