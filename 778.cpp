#include <vector>
#include <climits>

class Solution { // Oct 06, 2025
private:
  std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int dfs(int y, int x, std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& memo, std::vector<std::vector<bool>> visited) {
    if (y == grid.size() - 1 && x == grid[0].size() - 1) return grid[y][x];
    if (memo[y][x] != -1) return memo[y][x];
    visited[y][x] = true;

    int res = INT_MAX;
    for (std::vector<int> i : dirs) {
      int ny = y + i[0];
      int nx = x + i[1];
      if (ny >= 0 && ny < grid.size() && nx >= 0 && nx < grid[0].size()) {
        if (!visited[ny][nx]) {
          res = std::min(res, dfs(ny, nx, grid, memo, visited));
        }
      }
    }

    res = std::max(res, grid[y][x]);
    memo[y][x] = res;
    return res;
  }

public:
  int swimInWater(std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> memo(grid.size(), std::vector<int>(grid[0].size(), -1));
    return dfs(0, 0, grid, memo, std::vector<std::vector<bool>>(grid.size(), std::vector<bool>(grid[0].size(), false)));
  }
};
