#include <vector>

class Solution { // Aug 22, 2025
public:
  int minimumArea(std::vector<std::vector<int>>& grid) {
    int top = -1;
    for(int row = 0; row < grid.size(); row++) { // Top
      for(int col = 0; col < grid[0].size(); col++) {
        if(grid[row][col] == 1) {
          top = row;
          break;
        }
      }
      if(top != -1) break;
    }

    int bottom = -1;
    for(int row = grid.size()-1; row >= 0; row--) { // Bottom
      for(int col = grid[0].size()-1; col >= 0; col--) {
        if(grid[row][col] == 1) {
          bottom = row;
          break;
        }
      }
      if(bottom != -1) break;
    }

    int left = -1;
    for(int col = 0; col < grid[0].size(); col++) { // Left
      for(int row = 0; row < grid.size(); row++) {
        if(grid[row][col] == 1) {
          left = col;
          break;
        }
      }
      if(left != -1) break;
    }

    int right = -1;
    for(int col = grid[0].size()-1; col >= 0; col--) { // Right
      for(int row = grid.size()-1; row >= 0; row--) {
        if(grid[row][col] == 1) {
          right = col;
          break;
        }
      }
      if(right != -1) break;
    }

    return ((bottom-top)+1)*((right-left)+1);
  }
};
