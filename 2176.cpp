#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

class Solution { // Apr 17, 2025
public:
  int countPairs(std::vector<int>& nums, int k) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
      for(int j = i + 1; j < nums.size(); j++) {
        if(nums[i] == nums[j] && (long long)i * j % k == 0) {
          count++;
        }
      }
    }
    return count;
  }
};

void testSolution(std::vector<int> nums, int k, int expected) {
  Solution res;
  int ans = res.countPairs(nums, k);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "K: " << k << std::endl;

  std::cout << "Answer: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({3,1,2,2,2,1,3}, 2, 4);
  testSolution({1,2,3,4}, 1, 0);
}
