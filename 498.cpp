#include<vector>

class Solution { // Aug 25, 2025
public:
  std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
    std::vector<int> res;
    int n = mat[0].size()*mat.size();
    res.reserve(n);
    bool rightUp = true;
    int x = 0;
    int y = 0;
    while(res.size() != n) {
      while(y >= 0 && y < mat.size() && x >= 0 && x < mat[0].size()) {
        res.push_back(mat[y][x]);
        if(rightUp) {
          x++;
          y--;
        } else {
          y++;
          x--;
        }
      }
      if(rightUp) {
        x--;
        y++;
      } else {
        y--;
        x++;
      }
      if(rightUp) {
        if(x+1 < mat[0].size()) x++;
        else y++;
      } else {
        if(y+1 < mat.size()) y++;
        else x++;
      }
      rightUp = !rightUp;
    }

    return res;
  }
};
