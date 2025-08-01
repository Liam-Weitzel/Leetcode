#include <vector>

class Solution { // Aug 01, 2025
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    for(int i = 0; i < numRows; i++) res.emplace_back(i+1, 0);

    for(int row = 0; row < res.size(); row++) {
      for(int col = 0; col < res[row].size(); col++) {
        if(col == 0 || col == res[row].size()-1) res[row][col] = 1;
        else res[row][col] = res[row-1][col-1] + res[row-1][col];
      }
    }

    return res;
  }
};
