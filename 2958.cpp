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

#include <unordered_map>
class Solution2 { // Aug 12, 2026
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        // std::unordered_map<int, int> freq;
        // better as max heap?
        // we would get O(1) max finding but lose O(1) direct access
        // meaning for decrementing which also happens every step
        // we have a net negative
        // is there a datastructure that mixes heap and map? -> hash heap
        // O(1) lookups, O(logn) max/min, O(logn) updates
        // We don't need to know the max so unordered map is correct
        // if we add nums[right] ONLY the freq of nums[right] changes...
        // so we don't need to check the max... we just need to check if the freq of nums[right] > k
        // ezpz....
        std::unordered_map<int, int> freq;
        int left = 0;
        int max = 0;
        for(int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            while(freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            max = std::max(right-left+1, max);
        }
        return max;
    }
};
