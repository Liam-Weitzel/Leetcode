#include <iostream>
#include <vector>

class Solution { // Apr 30, 2025
public:
  int findNumbers(std::vector<int>& nums) {
    std::vector<float> numsF(nums.size());
    for(int i = 0; i < nums.size(); i++) numsF[i] = (float) nums[i];
    int count = 0;

    for(float i : numsF) {
      int digits = 0;
      while( i >= 1 ) {
        i = i/10;
        digits++;
      }
      if(digits%2==0) {
        count++;
      }
    }

    return count;
  }
};

void testSolution(std::vector<int> nums, int expected) {
  Solution res;
  int ans = res.findNumbers(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({12,345,2,6,7896}, 2);
  testSolution({555,901,482,1771}, 1);
}
