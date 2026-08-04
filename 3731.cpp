#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution { // Aug 04, 2026
public:
  std::vector<int> findMissingElements(std::vector<int>& nums) {
    int minVal = *std::min_element(nums.begin(), nums.end());
    int maxVal = *std::max_element(nums.begin(), nums.end());

    std::unordered_set<int> numsSet(nums.begin(), nums.end());
    
    std::vector<int> res;
    for(int i = minVal; i < maxVal; i++)
        if(!numsSet.contains(i)) res.push_back(i);

    return res;
  }
};
