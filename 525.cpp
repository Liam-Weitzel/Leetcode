#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

class Solution { // Mar 16, 2024
public:
  int findMaxLength(std::vector<int>& nums) {
    auto n = nums.size();
    std::vector<int> zerosLeftOf(n, 0);
    std::vector<int> onesLeftOf(n, 0);
    int zerosSoFar = 0;
    int onesSoFar = 0;

    for(int i = 0; i < n; ++i) {
      if(nums[i] == 1) onesSoFar++;
      if(nums[i] == 0) zerosSoFar++;
      zerosLeftOf[i] = zerosSoFar;
      onesLeftOf[i] = onesSoFar;
    }

    std::unordered_map<int, int> minElWithDiff;
    for(int i = 0; i < n; ++i) {
      if(minElWithDiff.find(zerosLeftOf[i]-onesLeftOf[i]) != minElWithDiff.end()) {
        minElWithDiff[zerosLeftOf[i]-onesLeftOf[i]] = std::min(i, minElWithDiff[zerosLeftOf[i]-onesLeftOf[i]]);
      } else minElWithDiff[zerosLeftOf[i]-onesLeftOf[i]] = i;
    }

    int res = 0;
    for(int i = n-1; i >= 0; --i) {
      if(zerosLeftOf[i]-onesLeftOf[i] == 0) {
        res = std::max(res, i+1);
      }
      if(minElWithDiff.find(zerosLeftOf[i]-onesLeftOf[i]) != minElWithDiff.end()) {
        res = std::max(res, i-minElWithDiff[zerosLeftOf[i]-onesLeftOf[i]]);
      }
    }

    return res;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> nums = {0,1,0};
  std::cout << res->findMaxLength(nums) << std::endl;
  return 0;
}
