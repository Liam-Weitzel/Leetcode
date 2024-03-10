#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

class Solution { // Mar 10, 2024
public:
  std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    std::vector<int> res;

    for(int i : set2) {
      if(set1.find(i) != set1.end()) res.push_back(i);
    }

    return res;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> nums1 = {1,2,2,4,8,6,2};
  std::vector<int> nums2 = {2,2,6,3,3,9,11};

  std::cout << std::endl;
  for(int i : res->intersection(nums1, nums2)) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
  return 0;
}
