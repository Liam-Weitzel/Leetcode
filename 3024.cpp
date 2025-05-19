#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

class Solution { // May 19, 2025
public:
  std::string triangleType(std::vector<int>& nums) {
    if(nums.size() != 3) return "none";
    int max = *std::max_element(nums.begin(), nums.end());
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if(max >= sum - max) return "none";

    std::set<int> s(nums.begin(), nums.end());
    int size = s.size();
    if(size == 3) return "scalene";
    else if (size == 2) return "isosceles";
    else if (size == 1) return "equilateral";

    return "none";
  }
};

void testSolution(std::vector<int> nums, std::string expected) {
  Solution res;
  std::string ans = res.triangleType(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;

  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({3,3,3}, "equilateral");
  testSolution({3,4,5}, "scalene");
}
