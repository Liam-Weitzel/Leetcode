#include <iostream>
#include <set>
#include <vector>

class Solution { // Jan 16, 2024
private:
  void dfs(std::vector<int> nums, std::set<int>& possibleSums, int currDepth, int currSum, std::set<int> alreadyPicked, int lastPicked){
    possibleSums.insert(currSum);
    alreadyPicked.insert(lastPicked);
    if(currDepth < nums.size()) {
      for(int i = 0; i < nums.size(); i++) {
        if(alreadyPicked.find(i) == alreadyPicked.end())
        dfs(nums, possibleSums, currDepth+1, currSum+nums[i], alreadyPicked, i);
      }
    }
  }

public:
  int minPatches(std::vector<int> nums, int n) {
    //Compute all possible sums with recursion...
    std::set<int> possibleSums;
    dfs(nums, possibleSums, 0, 0, *(new std::set<int>()), -1);

    int res = 0;
    for(int i = 1; i <= n; i++) {
      //Do we have to add N to the vector to get the sum?
      if(possibleSums.find(i) == possibleSums.end()) {
        res++;
        std::set<int> copyOfPossibleSums = possibleSums;
        for(int j : copyOfPossibleSums) {
          possibleSums.insert(i+j);
        }
      }
    }
    return res;
  }
};

void testSolution(std::vector<int> nums, int n, int expected) {
  Solution res;
  int ans = res.minPatches(nums, n);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Input: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,3}, 6, 1);
  testSolution({1,5,10}, 20, 2);
  testSolution({1,2,2}, 5, 0);
  testSolution({1,2,31,33}, 214745, 15);
}
