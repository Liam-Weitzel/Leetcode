#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

class Solution { // Jun 12, 2024
public:
  void sortColors(std::vector<int>& nums) {
    int l = 0, m = 0, r = nums.size() - 1;
    while (m <= r){
      if (nums[m] == 0) std::swap(nums[l++], nums[m++]);
      else if (nums[m] == 1) m++;
      else if (nums[m] == 2) std::swap(nums[m], nums[r--]);
    }
  }
};

void testSolution(std::vector<int> nums, std::vector<int> expected) {
  std::vector<int> input = nums;
  Solution res;
  res.sortColors(nums);

  if(nums == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Input: ";
  for(int i : input) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl;
  std::cout << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({2,0,2,1,1,0}, {0,0,1,1,2,2});
  testSolution({2,0,1}, {0,1,2});
  testSolution({1,0}, {0,1});
  testSolution({0}, {0});
  testSolution({0,0,1,2,1,0,0,2,1,1,0,2,1,1}, {0,0,0,0,0,1,1,1,1,1,1,2,2,2});
}
