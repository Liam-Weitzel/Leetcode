#include <vector>

class Solution { // Jul 17, 2026
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    for(int row = 1; row <= numRows; row++) {
      res.push_back(std::vector<int>(row));
      res.back().front() = 1;
      if(row > 1) res.back().back() = 1;
      
      for(int col = 1; col < row-1; col++)
        res.back()[col] = (*(res.end() - 2))[col] + (*(res.end() - 2))[col-1];
    }
    return res;
  }
};

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
