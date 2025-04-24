#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

class Solution { // Apr 24, 2025
public:
  int countCompleteSubarrays(std::vector<int>& nums) {
    int k = std::unordered_set<int>(nums.begin(),nums.end()).size();
    std::map<int, int> numCount;
    int res = 0;
    int left = 0;

    for(int i = 0; i < nums.size(); i++) {
      numCount[nums[i]]++;
      while(numCount.size() == k) {
        res += nums.size() - i;
        numCount[nums[left]]--;
        if (numCount[nums[left]] == 0) numCount.erase(nums[left]);
        left++;
      }
    }

    return res;
   // NOTE: Hint 2 says I could have just brute forced it... always check the constraints
  }
};

void testSolution(std::vector<int> nums, int expected) {
  Solution res;
  int ans = res.countCompleteSubarrays(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;

  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,3,1,2,2}, 4);
  testSolution({5,5,5,5}, 10);
}
