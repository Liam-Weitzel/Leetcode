#include <climits>
#include <vector>

class Solution { // Jun 16, 2025
public:
  int maximumDifference(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> sufMax(n, 0);
    sufMax[n-1] = nums[n-1];
    for(int i = n-2; i >= 0; i--) {
      sufMax[i] = std::max(nums[i], sufMax[i+1]);
    }

    int maxDiff = INT_MIN;
    for(int i = 0; i < n; i++) {
      maxDiff = std::max(maxDiff, sufMax[i] - nums[i]);
    }

    if(maxDiff <= 0) maxDiff = -1;
    return maxDiff;
  }
};
