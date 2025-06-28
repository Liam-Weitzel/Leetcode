#include <algorithm>
#include <vector>

class Solution { // Jun 28, 2025
public:
  std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<std::pair<int, int>> withIndex;
    for (int i = 0; i < n; ++i)
      withIndex.emplace_back(nums[i], i);

    std::sort(withIndex.begin(), withIndex.end(), [](auto& a, auto& b) {
      return a.first > b.first;
    });

    std::vector<std::pair<int, int>> topK(withIndex.begin(), withIndex.begin() + k);

    std::sort(topK.begin(), topK.end(), [](auto& a, auto& b) {
      return a.second < b.second;
    });

    std::vector<int> res;
    for (auto& p : topK)
      res.push_back(p.first);

    return res;
  }
};
