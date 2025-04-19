#include <algorithm>
#include <iostream>
#include <vector>

/*
testSolution({0,1,7,4,4,5}, 3, 6, 6);

0,1,2,4,4,5,7 - 3 - 6
^   l     h

0,1,2,4,4,5,7 - 3 - 6
  ^ l     h

0,1,2,4,4,5,7 - 3 - 6
    ^ l h

0,1,2,4,4,5,7 - 3 - 6
      ^

once in the beginning find the high from back,
then back off from that ptr as i increases.
do the same with low.
this way we are iterating over the array O(3N)
*/

class Solution { // Apr 19, 2025
public:
  long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
    std::sort(nums.begin(), nums.end());

    int high = nums.size()-1;
    int low = 0;
    long long count = 0;

    for(int i = 0; i < nums.size(); i++) {
      int high = upper_bound(nums.begin() + i + 1, nums.end(), 
                             upper - nums[i]) - nums.begin() - 1;
      int low = lower_bound(nums.begin() + i + 1, nums.end(), 
                            lower - nums[i]) - nums.begin();
      
      if (low <= high) {
        count += high - low + 1;
      }
    }
    return count;
  }
};

void testSolution(std::vector<int> nums, int lower, int upper, long long expected) {
  Solution res;
  long long ans = res.countFairPairs(nums, lower, upper);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Lower: " << lower << std::endl;

  std::cout << "Upper: " << upper << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({0,1,7,4,4,5}, 3, 6, 6);
  testSolution({1,7,9,2,5}, 11, 11, 1);
}
