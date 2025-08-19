#include <vector>

class Solution {
public:
  long long zeroFilledSubarray(std::vector<int>& nums) {
    long long count = 0;
    int left = -1;
    for(int right = 0; right < nums.size(); right++) {
      if(nums[right] == 0) {
        count += right - left;
      } else {
        left = right;
      }
    }
    return count;
  }
};
