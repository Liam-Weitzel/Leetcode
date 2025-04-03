#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

class Solution { // Apr 03, 2025
public:
  long long maximumTripletValue(std::vector<int>& nums) {
    std::vector<int> pre_ij(nums.size());
    int max_i = nums[0];
    for(int j = 1; j < nums.size()-1; j++) {
      pre_ij[j] = max_i-nums[j];
      if(nums[j] >= max_i && j != nums.size()-1) max_i = nums[j];
    }

    std::vector<int> max_after_i(nums.size());
    int max_so_far = 0;
    for(int i = nums.size()-1; i >= 0; i--) {
      max_after_i[i] = max_so_far;
      max_so_far = std::max(nums[i], max_so_far);
    }

    long long max = 0;
    for(int i = 0; i < nums.size(); i++) {
      max = std::max((long long)pre_ij[i]*(long long)max_after_i[i], max);
    }
    return max;
  }
};

void testSolution(std::vector<int> nums, long long expected) {
  Solution res;
  long long ans = res.maximumTripletValue(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Questions: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Answer: \"" << ans << "\"" << std::endl;

  std::cout << "Expected: \"" << expected << "\"" << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({12,6,1,2,7}, 77);
  testSolution({1,10,3,4,19}, 133);
  testSolution({1,2,3}, 0);
  testSolution({1000000,1,1000000}, 999999000000);
  testSolution({10,13,6,2}, 14);
}
