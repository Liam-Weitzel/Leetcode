#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

class Solution { // Mar 29, 2024
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

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> nums = {1,3,2,3,3};
  int k = 2;
  std::cout << res->countSubarrays(nums, k) << std::endl;
  return 0;
}
