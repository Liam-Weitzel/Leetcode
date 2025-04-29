#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Solution { // Apr 29, 2025
public:
  long long countSubarrays(std::vector<int>& nums, int k) {
    int maxNum = *max_element(nums.begin(), nums.end());
    int left = 0;
    int right = 0;
    int count = 0;
    long long res = 0;

    while (right < nums.size()) {
      if (nums[right] == maxNum) count++;
      while (count >= k) {
        res += nums.size() - right;
        if (nums[left] == maxNum) count--;
        left++;
      }
      right++;
    }

    return res;
  }
};

class Solution_old { // Mar 29, 2024
public:
  long long countSubarrays(std::vector<int>& nums, int k) {
    std::vector<int>::iterator maxElIter = std::max_element(nums.begin(), nums.end());
    int maxElIndex = std::distance(nums.begin(), maxElIter);
    int maxEl = nums[maxElIndex];

    int leftPtr = 0;
    int rightPtr = 0;
    long long maxElFreqInWin = (nums[0] == maxEl ? 1 : 0);
    long long res = (maxElFreqInWin == 1 && k == 1 ? nums.size() : 0);

    while(leftPtr < nums.size() && rightPtr < nums.size()) {
      if(maxElFreqInWin >= k) {
        if(nums[leftPtr] == maxEl) maxElFreqInWin--;
        leftPtr++;
      } else {
        rightPtr++;
        if(rightPtr < nums.size() && nums[rightPtr] == maxEl) maxElFreqInWin++;
      }
      if(maxElFreqInWin >= k) {
        res += nums.size()-rightPtr;
      }
    }

    return res;
  }
};

void testSolution(std::vector<int> nums, int k, long long expected) {
  Solution res;
  long long ans = res.countSubarrays(nums, k);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "K: " << k << std::endl;

  std::cout << "Output: " << ans << std::endl;;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,3,2,3,3}, 2, 6);
  testSolution({1,4,2,1}, 3, 0);
  testSolution({28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49}, 1, 187);
}
