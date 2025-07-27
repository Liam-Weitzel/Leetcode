#include <vector>

class Solution { // Jul 27, 2025
public:
  int countHillValley(std::vector<int>& nums) {
    std::vector<int> numsUnique;
    numsUnique.push_back(nums[0]);
    for(int i = 1; i < nums.size(); i++) {
      if(nums[i] != nums[i-1]) numsUnique.push_back(nums[i]);
    }

    int count = 0;
    for(int i = 1; i < numsUnique.size()-1; i++) {
      if(numsUnique[i] > numsUnique[i-1] && numsUnique[i] > numsUnique[i+1]) count++;
      else if(numsUnique[i] < numsUnique[i-1] && numsUnique[i] < numsUnique[i+1]) count++;
    }

    return count;
  }
};
