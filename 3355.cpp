#include <iostream>
#include <vector>

class Solution { // May 20, 2025
public:
  bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    std::vector<int> diffArray(nums.size()+1);
    for(std::vector<int> i : queries) {
      diffArray[i[0]]++;
      diffArray[i[1]+1]--;
    };
    
    int sum = 0;
    for(int i = 0; i < diffArray.size(); i++) {
      sum += diffArray[i];
      diffArray[i] = sum;
    }

    for(int i = 0; i < nums.size(); i++) {
      nums[i] = std::max(nums[i] - diffArray[i], 0);
      if(nums[i] != 0) return false;
    }

    return true;
  }
};

void testSolution(std::vector<int> nums, std::vector<std::vector<int>> queries, bool expected) {
  Solution res;
  int ans = res.isZeroArray(nums, queries);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: " << std::endl;
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Queries: " << std::endl;
  for(std::vector<int> i : queries) {
    std::cout << "[ ";
    for(int j : i) std::cout << j << ", ";
    std::cout << " ], ";
  }
  std::cout << std::endl;

  std::cout << "Ans: " << ans << std::endl;

  std::cout << "Epected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,0,1}, {{0,2}}, true);
  testSolution({4,3,2,1}, {{1,3},{0,2}}, false);
}
