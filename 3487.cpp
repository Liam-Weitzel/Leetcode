#include <algorithm>
#include <set>
#include <vector>

class Solution { // July 25, 2025
public:
  int maxSum(std::vector<int>& nums) {
    std::set<int> seen;
    int res = 0;
    for(int i : nums) {
      if(i > 0 && !seen.contains(i)) res += i;
      seen.insert(i);
    }
    if(res == 0) res = *std::max_element(nums.begin(), nums.end());
    return res;
  }
};
