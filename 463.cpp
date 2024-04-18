#include <iostream>
#include <memory>
#include <vector>

class Solution { // Apr 18, 2024
public:
  int islandPerimeter(std::vector<std::vector<int>>& grid) {
    int sum = 0;

    for(int y = 0; y < grid.size(); ++y) {
      for(int x = 0; x < grid[y].size(); ++x) {
        if(grid[y][x] == 1) {
          if(y-1 < 0 || grid[y-1][x] == 0) sum++;
          if(y+1 >= grid.size() || grid[y+1][x] == 0) sum++;
          if(x-1 < 0 || grid[y][x-1] == 0) sum++;
          if(x+1 >= grid[y].size() || grid[y][x+1] == 0) sum++;
        }
      }
    }

    return sum;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<std::vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
  std::cout << res->islandPerimeter(grid) << std::endl;
  return 0;
}
