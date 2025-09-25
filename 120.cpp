#include <vector>

class Solution { // Sep 25, 2025
public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    for(int i = triangle.size()-2; i >= 0; i--) {
      for(int j = 0; j < triangle[i].size(); j++) {
        triangle[i][j] += std::min(triangle[i+1][j], triangle[i+1][j+1]);
      }
    }
    return triangle[0][0];
  }
};
