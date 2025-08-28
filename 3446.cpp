#include <algorithm>
#include <vector>

class Solution { // Aug 28, 2025
private:
  std::vector<int> get_diagonal(const std::vector<std::vector<int>>& grid, int row, int col) {
    std::vector<int> diag;
    int n = grid.size();
    while (row < n && col < n) {
      diag.push_back(grid[row][col]);
      ++row;
      ++col;
    }
    return diag;
  }

  void set_diagonal(std::vector<std::vector<int>>& grid, int row, int col, const std::vector<int>& diag) {
    int idx = 0;
    int n = grid.size();
    while (row < n && col < n && idx < diag.size()) {
      grid[row][col] = diag[idx++];
      ++row;
      ++col;
    }
  }
public:
  std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid) {
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
      std::vector<int> diag = get_diagonal(grid, i, 0);
      std::sort(diag.begin(), diag.end(), std::greater());
      set_diagonal(grid, i, 0, diag);
    }

    for (int j = 1; j < n; ++j) {
      std::vector<int> diag = get_diagonal(grid, 0, j);
      std::sort(diag.begin(), diag.end(), std::less());
      set_diagonal(grid, 0, j, diag);
    }

    return grid;
  }
};
