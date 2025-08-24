#include <vector>

class Solution { // Aug 24, 2025
public:
  int longestSubarray(std::vector<int>& nums) {
    int currCount, maxCount, left;
    currCount = maxCount = left = 0;
    int lastZero = -1;
    bool zeroFound = false;

    for(int right = 0; right < nums.size(); right++) {
      if(nums[right] == 1) {
        currCount++;
        maxCount = std::max(currCount, maxCount);
      } else {
        if(zeroFound) {
          left = lastZero+1;
          currCount = right - left;
        } else {
          zeroFound = true;
        }
        lastZero = right;
      }
    }

    if(!zeroFound) return maxCount-1;

    return maxCount;
  }
};
