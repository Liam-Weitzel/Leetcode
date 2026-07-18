#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

class Solution { // Jul 18, 2026
public:
  long long maxSum(std::vector<std::vector<int>>& grid, std::vector<int>& limits, int k) {
    // O(NlogN) as I find max using sort... but easy to do O(N)
    std::vector<int> possible;
    for(int i = 0; i < grid.size(); i++) {
      std::sort(grid[i].begin(), grid[i].end(), std::greater<int>());
      for(int j = 0; j < limits[i]; j++) possible.push_back(grid[i][j]);
    }
    std::sort(possible.begin(), possible.end(), std::greater<int>());
    return std::accumulate(possible.begin(), possible.begin()+k, 0LL);
  }
};
