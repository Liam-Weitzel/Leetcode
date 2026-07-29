#include <climits>
#include <set>
#include <utility>
#include <vector>

class Solution { // Jul 29, 2026
private:
  int dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& memo, int row, int col, std::set<std::pair<int, int>> visited) {
    if(grid[row][col] == 1) memo[row][col] = 0;
    if(memo[row][col] != -1) return memo[row][col];
    std::pair<int,int> cur = std::make_pair(row, col);
    if(visited.contains(cur)) return INT_MAX;
    visited.insert(cur);

    int min = INT_MAX;

    if(row > 0) min = std::min(dfs(grid, memo, row - 1, col, visited), min);
    if(row < grid.size()-1) min = std::min(dfs(grid, memo, row + 1, col, visited), min);
    if(col > 0) min = std::min(dfs(grid, memo, row, col - 1, visited), min);
    if(col < grid[0].size()-1) min = std::min(dfs(grid, memo, row, col + 1, visited), min);

    if (min != INT_MAX) min++;
    memo[row][col] = min;
    return min;
  }

public:
  int maxDistance(std::vector<std::vector<int>>& grid) {
    //bfs/dfs = brute force
    //we can do memoized bfs/dfs
    //sub problem: what is the manhattan distance to the closest land?

    std::vector<std::vector<int>> memo(grid.size(), std::vector<int>(grid[0].size(), -1));
    int max = INT_MIN;
    for(int row = 0; row < grid.size(); row++) {
      for(int col = 0; col < grid[0].size(); col++) {
        int cur = dfs(grid, memo, row, col, std::set<std::pair<int, int>>());
        if(cur != INT_MAX) max = std::max(cur, max);
      }
    }

    //it turns out DFS + memo doesnt work efficiently because we need to start BFS from every land cell simultaneously.

    return max;
  }
};
