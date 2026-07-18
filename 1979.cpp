#include <algorithm>
#include <numeric>
#include <vector>

class Solution { // Jul 18, 2026
public:
  int findGCD(std::vector<int>& nums) {
    int max = *std::max_element(nums.begin(), nums.end());
    int min = *std::min_element(nums.begin(), nums.end());
    // std::gcd(max, min);
    while(min != max) {
      if(min > max)
        min -= max;
      else
        max -= min;
    }
    return min;
  }
};
