#include <algorithm>
#include <vector>

class Solution { // Oct 13, 2026
public:
  long long maxAlternatingSum(std::vector<int>& nums) {
    //the order of what is negative and what is positive doesnt matter
    //it only matters WHAT is negative and WHAT is positive
    //since we start with a positive (arr[0]) we always can allocate HALF to positive atleast,
    //in case of odd size, negative is size/2-2;
    //so that means if we sort nums, the first half will be allocated to positive, the second to negative...
    //CORRECTION: Negative numbers to the power of 2 are ALWAYS positive, meaning that we first abs all numbers before sorting...

    for(int i = 0; i < nums.size(); i++) nums[i] = std::abs(nums[i]);
    std::sort(nums.begin(), nums.end());

    long long res = 0;
    int i = 0;

    for(; i < nums.size()/2; i++)
      res -= nums[i] * nums[i];

    for(; i < nums.size(); i++)
      res += nums[i] * nums[i];

    return res;
  }
};
