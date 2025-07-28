#include <vector>

class Solution { // Jul 28, 2025
public:
  int countMaxOrSubsets(std::vector<int>& nums) {
    int n = nums.size();
    int maxOr = 0;
    int count = 0;

    for (int num : nums) {
      maxOr |= num;
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
      int currentOr = 0;
      for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == (1 << i)) {
          currentOr |= nums[i];
        }
      }
      if (currentOr == maxOr) count++;
    }

    return count;
  }
};
