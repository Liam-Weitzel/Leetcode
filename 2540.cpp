#include <memory>
#include <iostream>
#include <set>
#include <vector>

class Solution { // Mar 09, 2024
public:
  int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::set<int> set1(nums1.begin(), nums1.end());
    for(int i : nums2) {
      if(set1.find(i) != set1.end()) return i;
    }
    return -1;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> nums1 = {1,2,3};
  std::vector<int> nums2 = {2,4};
  std::cout << res->getCommon(nums1, nums2) << std::endl;
  return 0;
}
