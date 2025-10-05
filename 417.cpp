#include <vector>

class Solution { // Oct 05, 2025
private:
  std::vector<std::vector<int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};

  void dfs_mark(int y, int x, std::vector<std::vector<int>>& heights, std::vector<std::vector<int>>& memo, int oceanBit) {
    if ((memo[y][x] & oceanBit) != 0) return;
    memo[y][x] |= oceanBit;

    int m = heights.size();
    int n = heights[0].size();
    for (std::vector<int>& d : directions) {
      int ny = y + d[0];
      int nx = x + d[1];
      if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
      if (heights[ny][nx] >= heights[y][x]) {
        dfs_mark(ny, nx, memo, heights, oceanBit);
      }
    }
  }

public:
  std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) return {};
    int m = heights.size();
    int n = heights[0].size();

    std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) dfs_mark(i, 0, memo, heights, 1);
    for (int j = 0; j < n; ++j) dfs_mark(0, j, memo, heights, 1);
    for (int i = 0; i < m; ++i) dfs_mark(i, n - 1, memo, heights, 2);
    for (int j = 0; j < n; ++j) dfs_mark(m - 1, j, memo, heights, 2);

    std::vector<std::vector<int>> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (memo[i][j] == 3) result.push_back({i, j});
      }
    }
    return result;
  }
};
