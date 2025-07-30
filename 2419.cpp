#include <algorithm>
#include <vector>

class Solution { // Jul 30, 2025
public:
    int longestSubarray(std::vector<int>& nums) {
        int max = *std::max_element(nums.begin(), nums.end());
        
        int count = 0;
        int maxCount = 0;
        for(int i : nums) {
            if(i == max) {
                count++;
            } else {
                maxCount = std::max(maxCount, count);
                count = 0;
            }
        }
        maxCount = std::max(maxCount, count);
        return maxCount;
    }
};
