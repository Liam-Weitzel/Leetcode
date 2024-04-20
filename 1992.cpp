#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Solution { // Apr 20, 2024
private:
  std::pair<int, int> dfs(std::vector<std::vector<int>>& land, std::pair<int, int> coords) {
    int maxBottom = coords.first;
    int maxRight = coords.second;
    land[coords.first][coords.second] = 0;
    
    if(coords.first-1 >= 0 && land[coords.first-1][coords.second] == 1) {
      std::pair<int, int> temp = dfs(land, std::make_pair(coords.first-1, coords.second));
      maxBottom = std::max(temp.first, maxBottom);
      maxRight = std::max(temp.second, maxRight);
    }

    if(coords.first+1 < land.size() && land[coords.first+1][coords.second] == 1) {
      std::pair<int, int> temp = dfs(land, std::make_pair(coords.first+1, coords.second));
      maxBottom = std::max(temp.first, maxBottom);
      maxRight = std::max(temp.second, maxRight);
    }

    if(coords.second-1 >= 0 && land[coords.first][coords.second-1] == 1) {
      std::pair<int, int> temp = dfs(land, std::make_pair(coords.first, coords.second-1));
      maxBottom = std::max(temp.first, maxBottom);
      maxRight = std::max(temp.second, maxRight);
    }

    if(coords.second+1 < land[coords.first].size() && land[coords.first][coords.second+1] == 1) {
      std::pair<int, int> temp = dfs(land, std::make_pair(coords.first, coords.second+1));
      maxBottom = std::max(temp.first, maxBottom);
      maxRight = std::max(temp.second, maxRight);
    }

    return std::make_pair(maxBottom, maxRight);
  }
public:
  std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
    std::vector<std::vector<int>> res;

    for(int i = 0; i < land.size(); ++i) {
      for(int j = 0; j < land[i].size(); ++j) {
        if(land[i][j] == 1) {
          std::pair<int, int> last = dfs(land, std::make_pair(i, j));
          std::vector<int> temp = {i, j, last.first, last.second};
          res.push_back(temp);
        }
      }
    }

    return res;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<std::vector<int>> land = {{1,0,0},{0,1,1},{0,1,1}};
  land = res->findFarmland(land);
  for(std::vector<int> i : land) {
    for(int j : i) std::cout << j << ", ";
    std::cout << std::endl;
  }
  return 0;
}
