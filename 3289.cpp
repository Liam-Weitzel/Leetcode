#include <set>
#include <vector>

class Solution { // Oct 31, 2025
public:
  std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
    std::set<int> seen;
    std::vector<int> res;
    for(int i : nums) {
      if(seen.contains(i)) res.push_back(i);
      seen.insert(i);
    }
    return res;
  }
};
