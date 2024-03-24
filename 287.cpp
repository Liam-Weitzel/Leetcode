#include <iostream>
#include <memory>
#include <vector>

class Solution { // Mar 24, 2024
public:
  int findDuplicate(std::vector<int>& nums) {
    int fast = 0, slow = 0;

    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while(fast != slow);

    fast = 0;
    while(fast != slow) {
      fast = nums[fast];
      slow = nums[slow];
    }

    return slow;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> nums = {1,3,4,2,2};
  std::cout << res->findDuplicate(nums) << std::endl;
  return 0;
}
