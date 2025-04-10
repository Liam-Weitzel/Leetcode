#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

class Solution { // Apr 02, 2025
public:
  long long maximumTripletValue(std::vector<int>& nums) { // O(N^3)
    long long max = 0;
    for(int i = 0; i < nums.size()-2; i++) {
      for(int j = i+1; j < nums.size()-1; j++) {
        for(int k = j+1; k < nums.size(); k++) {
          long long curr = (long long)nums[i] * nums[k] - (long long)nums[j] * nums[k];
          if(max < curr) max = curr;
        }
      }
    }
    return max;
  }
};

void testSolution(std::vector<int> nums, long long expected) {
  Solution res;
  long long ans = res.maximumTripletValue(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Questions: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Answer: \"" << ans << "\"" << std::endl;

  std::cout << "Expected: \"" << expected << "\"" << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({12,6,1,2,7}, 77);
  testSolution({1,10,3,4,19}, 133);
  testSolution({1,2,3}, 0);
  testSolution({1000000,1,1000000}, 999999000000);
  testSolution({10,13,6,2}, 14);
}
