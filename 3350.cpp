#include <vector>
#include <set>

class Solution { // Oct 15, 2025
private:
  int isSequenceStrictlyIncreasing(std::vector<int>& nums, int left, int right) {
    for(int j = left+1; j <= right; j++) {
      if(nums[j] > nums[j-1]) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  }
  bool hasIncreasingSubarrays(std::vector<int>& nums, int k) {
    if(nums.size() < k*2) return false;
    std::set<int> ranges;
    int left = 0;
    for(int right = k-1; right < nums.size(); right++) {
      bool increasing = isSequenceStrictlyIncreasing(nums, left, right);
      if(increasing) ranges.insert(left);
      left++;
    }
    for(int i = 0; i < nums.size()-k; i++) {
      if(ranges.find(i) != ranges.end() && ranges.find(i+k) != ranges.end()) return true;
    }
    return false;
  }
public:
  int maxIncreasingSubarrays(std::vector<int>& nums) {
    int n = nums.size();
    for (int k = n / 2; k >= 1; --k) {
      if (hasIncreasingSubarrays(nums, k)) return k;
    }
    return 0;
  }
};
