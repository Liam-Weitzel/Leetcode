#include <iostream>
#include <vector>

class Solution { // Apr 27, 2025
public:
  int countSubarrays(std::vector<int>& nums) {
    int count = 0;
    for(int i = 0; i <= nums.size()-3; i++) {
      if(((nums[i]+nums[i+2])*2) == nums[i+1]) count++;
    }
    return count;
  }
};

void testSolution(std::vector<int> nums, int expected) {
  Solution res;
  int ans = res.countSubarrays(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: " << std::endl;
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Ans: " << ans << std::endl;

  std::cout << "Epected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,2,1,4,1}, 1);
  testSolution({1,1,1}, 0);
}
