#include <iostream>
#include <ostream>
#include <set>
#include <vector>

class Solution { // Jan 15, 2026
public:
  bool containsDuplicate(std::vector<int> nums) {
    std::set<int> seen;
    for(int i : nums) {
      if(seen.find(i) != seen.end()) return true;
      seen.insert(i);
    };
    return false;
  }
};

void testSolution(std::vector<int> nums, bool expected) {
  Solution res;
  bool ans = res.containsDuplicate(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "ans: " << ans << std::endl;

  std::cout << "expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,2,3,1}, true);
  testSolution({1,2,3,4}, false);
  testSolution({1,1,1,3,3,4,3,2,4,2}, true);
}
