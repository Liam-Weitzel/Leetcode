#include <vector>

class Solution { // Sep 30, 2025
public:
  int triangularSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> triangle;
    triangle.push_back(nums);

    auto last = triangle.end() - 1;
    while (last->size() != 1) {
      std::vector<int> cur;
      for (int i = 1; i < last->size(); i++) {
        cur.push_back(((*last)[i] + (*last)[i - 1]) % 10);
      }
      triangle.push_back(cur);
      last = triangle.end() - 1;
    }
    return (*last)[0];
  }
};
