#include <vector>

class Solution { // Jul 20, 2026
public:
  std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
    std::vector<std::vector<int>> res = grid;
    for(int i = 0; i < k; i++) {
      std::vector<std::vector<int>> temp(res.size(), std::vector<int>(res[0].size(), 0));
      for(int row = 0; row < res.size(); row++) {
        for(int col = 0; col < res[0].size(); col++) {
          if(row == 0 && col == 0)
            temp[row][col] = res.back().back();
          else if(col == 0)
            temp[row][col] = res[row-1].back();
          else
            temp[row][col] = res[row][col-1];
        }
      }
      res = temp;
    }
    return res;
  }
};
