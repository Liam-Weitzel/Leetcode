#include <vector>

class Solution { // Nov 12, 2026
public:
  int longestMonotonicSubarray(std::vector<int>& nums) {
    /*
    Input: nums = [1,4,3,3,2]
    Output: 2
    Explanation:
    The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
    The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
    Hence, we return 2.
    */

    int longest = 1;
    int curDec = 1;
    int curInc = 1;

    for(int i = 1; i < nums.size(); ++i) {
      int cur = nums[i];
      int prev = nums[i-1];

      if(prev < cur) {
        curInc++;
        curDec = 1;
      } else if(prev > cur) {
        curDec++;
        curInc = 1;
      } else {
        curInc = 1;
        curDec = 1;
      }

      longest = std::max(curDec, std::max(curInc, longest));
    }

    return longest;
  }
};
