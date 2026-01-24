#include <vector>

class Solution {
public:
  int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size()-1;
    int mid = (left+right)/2;

    while(left != right) {
      if(nums[mid] >= nums[0]) {
        left = mid + 1;
      } else {
        right = mid;
      }
      mid = (left+right)/2;
    }

    return std::min(nums[0], nums[mid]);
  }
};
