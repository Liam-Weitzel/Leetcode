#include <iostream>
#include <map>
#include <ostream>
#include <vector>

class Solution { // Jan 15, 2026
public:
  std::vector<int> twoSum(std::vector<int> nums, int target) {
    std::map<int, int> map; //num, index
    for(int i = 0; i < nums.size(); i++) {
      int cur = nums[i];
      int search = target-cur;
      if(map.find(search) != map.end()) return {map[search], i};
      map[cur] = i;
    }
    return {};
  }
};

void testSolution(std::vector<int> nums, int target, std::vector<int> expected) {
  Solution res;
  std::vector<int> ans = res.twoSum(nums, target);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "target: " << target << std::endl;

  std::cout << "ans: ";
  for(int i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({2,7,11,15}, 9, {0, 1});
  testSolution({3,2,4}, 6, {1, 2});
  testSolution({3,3}, 6, {0, 1});
}
