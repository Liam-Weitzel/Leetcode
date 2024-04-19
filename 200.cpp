#include <iostream>
#include <memory>
#include <map>
#include <utility>
#include <vector>

class Solution { // Apr 19, 2024
private:
  void dfs(std::pair<int, int> coords, std::map<std::pair<int, int>, bool>& visited, std::vector<std::vector<char>>& grid) {
    visited[coords] = true;

    if(coords.first-1 >= 0 && 
      !visited[std::make_pair(coords.first-1, coords.second)] &&
      grid[coords.first-1][coords.second] == '1')
      dfs(std::make_pair(coords.first-1, coords.second), visited, grid);

    if(coords.first+1 < grid.size() &&
      !visited[std::make_pair(coords.first+1, coords.second)] &&
      grid[coords.first+1][coords.second] == '1')
      dfs(std::make_pair(coords.first+1, coords.second), visited, grid);

    if(coords.second-1 >= 0 &&
      !visited[std::make_pair(coords.first, coords.second-1)] &&
      grid[coords.first][coords.second-1] == '1')
      dfs(std::make_pair(coords.first, coords.second-1), visited, grid);

    if(coords.second+1 < grid[coords.first].size() &&
      !visited[std::make_pair(coords.first, coords.second+1)] &&
      grid[coords.first][coords.second+1] == '1')
      dfs(std::make_pair(coords.first, coords.second+1), visited, grid);

    return;
  }

public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    std::map<std::pair<int, int>, bool> visited;
    int islandCount = 0;
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[i].size(); ++j) {
        std::pair<int, int> coords = std::make_pair(i, j);
        if(grid[coords.first][coords.second] == '1' && !visited[coords]) {
          dfs(coords, visited, grid);
          islandCount++;
        }
      }
    }
    return islandCount;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<std::vector<char>> grid = {{'1','1','1','1','0'},
                                         {'1','1','0','1','0'},
                                         {'1','1','0','0','0'},
                                         {'0','0','0','0','0'}};
  std::cout << res->numIslands(grid) << std::endl;
  return 0;
}
