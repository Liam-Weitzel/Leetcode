#include <map>
#include <vector>

class Solution { // Apr 08, 2025 - Was in a rush today
public:
  int minimumOperations(std::vector<int>& nums) {
    std::map<int, int> numCount;
    for(int i : nums) numCount[i]++;

    int start = 0;
    int i = 0;
    while(nums.size()-start >= 3) {
      int allOne = true;
      for(std::pair<int, int> entry : numCount) {
        if(entry.second > 1) {
          allOne = false;
          break;
        }
      }
      if(allOne) {
        return i;
      }
      i++;
      numCount[nums[start]]--;
      numCount[nums[start+1]]--;
      numCount[nums[start+2]]--;
      start += 3;
    }

    if(nums.size()-start > 0) {
      int allOne = true;
      for(std::pair<int, int> entry : numCount) {
        if(entry.second > 1) {
          allOne = false;
          break;
        }
      }
      if(!allOne) {
        i++;
      }
    }

    return i;
  }
};
