#include <functional>
#include <iostream>
#include <vector>

class Solution { // Jun 18, 2025
public:
  std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), std::greater<>());
    std::vector<std::vector<int>> res;
    for(int i = 0; i < nums.size(); i+=3) {
      res.push_back({nums[i], nums[i+1], nums[i+2]});
      if(std::abs(nums[i] - nums[i+1]) > k || std::abs(nums[i] - nums[i+2]) > k || std::abs(nums[i+1] - nums[i+2]) > k) return {}; 
    }
    return res;
  }
};

void testSolution(std::vector<int> nums, int k, std::vector<std::vector<int>> expected) {
  Solution res;
  std::vector<std::vector<int>> ans = res.divideArray(nums, k);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "K: " << k << std::endl;

  std::cout << "Output: ";
  for(std::vector<int> i : ans) {
    std::cout << "[";
    for(int j : i) {
      std::cout << j << ", ";
    }
    std::cout << "], ";
  }
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(std::vector<int> i : expected) {
    std::cout << "[";
    for(int j : i) {
      std::cout << j << ", ";
    }
    std::cout << "], ";
  }
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,3,4,8,7,9,3,5,1}, 2, {{1,1,3},{3,4,5},{7,8,9}});
  testSolution({2,4,2,2,5,2}, 2, {});
  testSolution({4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11}, 14, {{2,2,12},{4,8,5},{5,9,7},{7,8,5},{5,9,10},{11,12,2}});
}
