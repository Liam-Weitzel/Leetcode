#include <algorithm>
#include <climits>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution { // Mar 28, 2024
public:
  int maxSubarrayLength(std::vector<int>& nums, int k) {
    int right = 0, left = 0;
    int maxLen = INT_MIN, currLen = 0;
    std::unordered_map<int, int> freqMap;
    
    while(left < nums.size()) {
      if(right != nums.size() && freqMap[nums[right]] < k) { 
        freqMap[nums[right]]++;
        right++;
        currLen++;
      } else {
        freqMap[nums[left]]--;
        left++;
        currLen--;
      }
      maxLen = std::max(maxLen, currLen);
    }

    return maxLen;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> nums = {1,2,3,1,2,3,4,1,2,3,4};
  int k = 2;
  std::cout << res->maxSubarrayLength(nums, k) << std::endl;
  return 0;
}
