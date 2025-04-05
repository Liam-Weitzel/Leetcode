#include <iostream>
#include <vector>

class Solution { // Apr 05, 2025
private:
  void getPowerSet(std::vector<int>& nums, std::vector<std::vector<int>>& powerset, std::vector<int>& subset, int curr) {
    if (curr == nums.size()) {
      powerset.push_back(subset);
      return;
    }

    subset.push_back(nums[curr]);
    getPowerSet(nums, powerset, subset, curr+1);
    subset.pop_back();
    getPowerSet(nums, powerset, subset, curr+1);
  }

public:
  int subsetXORSum(std::vector<int>& nums) {
    if(nums.empty()) return 0;

    std::vector<int> subset;
    std::vector<std::vector<int>> powerset;
    getPowerSet(nums, powerset, subset, 0);

    int xorSum = 0;
    for(std::vector<int> i : powerset) {
      int curr = 0;
      for(int j : i) curr = curr^j;
      xorSum += curr;
    }

    return xorSum;
  }
};

void testSolution(std::vector<int> nums, int expected) {
  Solution res;
  int ans = res.subsetXORSum(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,3}, 6);
  testSolution({5,1,6}, 28);
  testSolution({3,4,5,6,7,8}, 480);
}
