#include <set>
#include <vector>

class Solution { // Aug 25, 2026
public:
  int missingMultiple(std::vector<int>& nums, int k) {
    int multiple = 1;
    std::set<int> numsSet(nums.begin(), nums.end());
    while(true) {
      int cur = multiple * k;
      if(!numsSet.contains(cur)) return cur;
      multiple++;
    }
    return 0;
  }
};
