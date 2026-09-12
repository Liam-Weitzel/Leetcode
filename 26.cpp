#include <vector>

class Solution { // Sep 12, 2026
public:
    int removeDuplicates(std::vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; --i)
            if(nums[i] == nums[i+1]) nums.erase(nums.begin()+i);
        return nums.size();
    }
};
