#include <algorithm>
#include <vector>

class Solution { // Aug 07, 2026
public:
  std::vector<int> applyOperations(std::vector<int>& nums) {
    //we need to apply n-1 operations to nums
    //in the ith operation, if nums[i] == nums[i+1],
    //then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, skip
    //then after all ops: shift all 0's to the right, return that.
    int n = nums.size();
    for(int i = 0; i < n-1; i++) {
      if(nums[i] == nums[i+1]) {
        nums[i] *= 2;
        nums[i+1] = 0;
      }
    }

    // Order matters so we can't do it like this, we actually have to shift them
    // int right = n-1;
    // int left = 0;
    // while(left < right) {
    //     if(nums[left] == 0) {
    //         //This can be optimized using XOR
    //         int tmp = nums[right];
    //         nums[right] = nums[left];
    //         nums[left] = tmp;
    //         right--;
    //         continue;
    //     }
    //     left++;
    // }

    // We're just going to make a new vec in the interest of time...
    int zeroCount = std::count_if(nums.begin(), nums.end(), [](int i)->bool{return i == 0;}); 
    std::vector<int> res;
    res.reserve(n);
    for(int i : nums) if(i != 0) res.push_back(i);
    for(int i = 0; i < zeroCount; i++) res.push_back(0);

    return res;
  }
};
