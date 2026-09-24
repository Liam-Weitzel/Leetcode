#include <vector>

class Solution { // Sep 24, 2026
private:
  int digitSum(int num) {
    int sum = 0;
    while(num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
public:
  int smallestIndex(std::vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++)
      if(digitSum(nums[i]) == i) return i;
    return -1;
  }
};
