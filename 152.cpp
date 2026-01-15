#include <climits>
#include <iostream>
#include <ostream>
#include <vector>

class Solution { // Jan 15, 2026
public:
  int maximumProductSubarray(std::vector<int> nums) {
    int n = nums.size();

    int runningProduct = 1;
    int maxProduct = INT_MIN;
    for(int i = 0; i < n; i++) {
      if(nums[i] != 0) {
        runningProduct *= nums[i];
        maxProduct = std::max(runningProduct, maxProduct);
      } else {
        runningProduct = 1;
        maxProduct = std::max(0, maxProduct);
      }
    }

    runningProduct = 1;
    for(int i = n-1; i >= 0; i--) {
      if(nums[i] != 0) {
        runningProduct *= nums[i];
        maxProduct = std::max(runningProduct, maxProduct);
      } else {
        runningProduct = 1;
        maxProduct = std::max(0, maxProduct);
      }
    }

    return maxProduct;
  }
};

void testSolution(std::vector<int> nums, int expected) {
  Solution res;
  int ans = res.maximumProductSubarray(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "ans: " << ans << std::endl;

  std::cout << "expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({2,3,-2,4}, 6);
  testSolution({0,2,3,-2,4}, 6);
  testSolution({-2,0,-1}, 0);
}
