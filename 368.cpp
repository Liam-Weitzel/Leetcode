#include <algorithm>
#include <iostream>
#include <vector>

class Solution { // Apr 06, 2025
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
  std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
    std::vector<std::vector<int>> powerset;
    std::vector<int> subset;
    getPowerSet(nums, powerset, subset, 0);

    std::sort(powerset.begin(), powerset.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a.size() > b.size();
    });

    for(std::vector<int> subset : powerset) {
      // std::cout << "Currently on: ";
      // for(int i : subset) std::cout << i << ", ";
      // std::cout << std::endl;

      bool moduloCheck = true;
      for(int i = 0; i < subset.size(); i++) {
        for(int j = i+1; j < subset.size(); j++) {
          if(subset[i] % subset[j] != 0 && subset[j] % subset[i] != 0) {
            // std::cout << "Failed because: " << i << " % " << j << " != 0" << std::endl;
            moduloCheck = false;
            break;
          }
        }
        if(!moduloCheck) break;
      }
      if(moduloCheck) return subset;
    }

    return nums;
  }
};

void testSolution(std::vector<int> nums, std::vector<int> expected) {
  Solution res;
  std::vector<int> ans = res.largestDivisibleSubset(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: ";
  for(int i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,2,3}, {1,2});
  testSolution({1,2,4,8}, {1,2,4,8});
  testSolution({3,4,16,8}, {4,8,16});
}
