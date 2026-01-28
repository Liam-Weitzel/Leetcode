#include <algorithm>
#include <climits>
#include <vector>

class Solution { // Jan 28, 2026
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    for(int i = 0; i < nums.size() - 2; i++) {
      if (i > 0 && nums[i] == nums[i-1]) continue;
      int j = i+1;
      int k = nums.size()-1;
      std::vector<int> prev = {INT_MIN, INT_MIN, INT_MIN};
      while(j != k) {
        int threeSum = nums[i] + nums[j] + nums[k];
        if(threeSum < 0) {
          j++;
        } else if (threeSum > 0) {
          k--;
        } else if (threeSum == 0) {
          std::vector<int> found = {nums[i],nums[j],nums[k]};
          if(prev != found) {
            res.push_back(found);
            prev = found;
          }
          j++;
        }
      }
    }
    return res;
  }
};
