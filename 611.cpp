#include <algorithm>
#include <functional>
#include <vector>

class Solution { // Sep 26, 2025
public:
  int triangleNumber(std::vector<int>& nums) {
    int count = 0;
    std::sort(nums.begin(), nums.end(), std::less<int>());
    for(int i = 0; i < nums.size(); i++) {
      for(int j = i+1; j < nums.size(); j++) {
        for(int z = j+1; z < nums.size(); z++) {
          if(nums[i] + nums[j] > nums[z]) {
            count++;
          }
          else break;
        }
      }
    }
    return count;
  }
};
