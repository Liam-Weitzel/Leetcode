#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

class Solution {
  public:
  int maxAdjacentDistance(std::vector<int>& nums) { // Jun 12, 2025
    auto n = nums.size();
    nums.push_back(nums[0]);
    int prev = nums[0];
    int max = INT_MIN;
    for(int i : nums) {
      max = std::max(max, std::abs(prev-i));
      prev = i;
    }
    return max;
  }
};

void testSolution(std::vector<int> nums, int expected) {
  Solution res;
  int ans = res.maxAdjacentDistance(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1, 2, 4}, 3);
  testSolution({-5, -10, -5}, 5);
}
