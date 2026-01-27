#include <algorithm>
#include <climits>
#include <iostream>
#include <ostream>
#include <vector>

class Solution { // Jan 15, 2026
public:
  int maxSubArray(std::vector<int> nums) {
    int n = nums.size();

    // nums       = -2,  1, -3,  4, -1,  2,  1, -5,  4
    // prefixSums = -2, -1, -4,  0, -1,  1,  2, -3,  1
    // suffixSums =  1,  3,  2,  5,  1,  2,  0, -1,  4
    // totalSum   =  1
    // Just find both maximums and add them and then minus the total sum? this is o(n) but wastes memory
    // I also found a way to do it without total sum and suffix sum.
    // ans        =  2 + 5 - 1 = 6

    std::vector<int> prefixSums(n, 0);
    prefixSums[0] = nums[0];
    for(int i = 1; i < n; i++)
      prefixSums[i] = prefixSums[i-1] + nums[i];
    int maxPrefix = *std::max_element(prefixSums.begin(), prefixSums.end());

    std::vector<int> suffixSums(n, 0);
    suffixSums[n-1] = nums[n-1];
    for(int i = n-2; i >= 0; i--)
      suffixSums[i] = suffixSums[i+1] + nums[i];
    int totalSum = suffixSums[0];
    int maxSuffix = *std::max_element(suffixSums.begin(), suffixSums.end());

    int res = maxPrefix + maxSuffix - totalSum;

    return res;
  }
};

class Solution2 { // Jan 27, 2026
public:
  int maxSubArray(std::vector<int> nums) {
    int n = nums.size();

    // Kadane's algorithm
    // Running sum, if it goes negative, its always better to start a new running sum. Track highest running sum

    int runningSum = 0;
    int maxSum = INT_MIN;

    for(int i : nums) {
      runningSum += i;
      maxSum = std::max(runningSum, maxSum);
      if(runningSum < 0) runningSum = 0;
    }

    return maxSum;
  }
};

void testSolution(std::vector<int> nums, int expected) {
  Solution2 res;
  int ans = res.maxSubArray(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "ans: " << ans << std::endl;

  std::cout << "expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({-2,1,-3,4,-1,2,1,-5,4}, 6);
  testSolution({1}, 1);
  testSolution({5,4,-1,7,8}, 23);
}
