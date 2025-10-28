#include <set>
#include <vector>

class Solution { // Oct 28, 2025
private:
  bool isValid(int curr, bool direction, std::vector<int> nums) {
    std::set<int> zeroIndices;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0)
        zeroIndices.insert(i);
    }

    while(zeroIndices.size() < nums.size()) {
      if(curr < 0 || curr >= nums.size()) return false;
      /* std::cout << "[";
      for (size_t i = 0; i < nums.size(); ++i) {
          if (i == curr)
              std::cout << "_" << nums[i] << "_";
          else
              std::cout << nums[i];

          if (i + 1 < nums.size())
              std::cout << ",";
      }
      std::cout << "] -> "; */
      if(nums[curr] == 0) {
        zeroIndices.insert(curr);
        if(direction) curr++;
        else curr--;
      } else if(nums[curr] > 0) {
        nums[curr]--;
        if(nums[curr] == 0) zeroIndices.insert(curr);
        direction = !direction;
        if(direction) curr++;
        else curr--;
      }
    }

    return true;
  }
public:
  int countValidSelections(std::vector<int> &nums) {
    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0) {
        // std::cout << "Choose curr = " << i << ", and movement direction to the right." << std::endl;
        res += isValid(i, true, nums);
        // std::cout << std::endl;
        // std::cout << std::endl;
        // std::cout << "Choose curr = " << i << ", and movement direction to the left." << std::endl;
        res += isValid(i, false, nums);
        // std::cout << std::endl;
        // std::cout << std::endl;
      }
    }
    return res;
  }
};
