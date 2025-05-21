#include <iostream>
#include <vector>

class Solution { // May 21, 2025
public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    bool firstColEdgeCase = false;
    for(int row = 0; row < matrix.size(); row++) {
      if(matrix[row][0] == 0) firstColEdgeCase = true;
      for(int col = 1; col < matrix[0].size(); col++) {
        if(matrix[row][col] == 0) {
          matrix[row][0] = 0;
          matrix[0][col] = 0;
        }
      }
    }

    for(int row = matrix.size()-1; row >= 0; row--) {
      for(int col = matrix[0].size()-1; col >= 1; col--) {
        if(matrix[row][0] == 0 || matrix[0][col] == 0) {
          matrix[row][col] = 0;
        }
      }
      if(firstColEdgeCase) matrix[row][0] = 0;
    }
  }
};

void testSolution(std::vector<std::vector<int>> matrix, std::vector<std::vector<int>> expected) {
  std::cout << "Matrix: " << std::endl;
  for(std::vector<int> i : matrix) {
    std::cout << "[ ";
    for(int j : i) {
      std::cout << j << ", ";
    }
    std::cout << " ]" << std::endl;
  }

  Solution res;
  res.setZeroes(matrix);

  if(matrix == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Output: " << std::endl;
  for(std::vector<int> i : matrix) {
    std::cout << "[ ";
    for(int j : i) {
      std::cout << j << ", ";
    }
    std::cout << " ]" << std::endl;
  }

  std::cout << "Expected: " << std::endl;
  for(std::vector<int> i : expected) {
    std::cout << "[ ";
    for(int j : i) {
      std::cout << j << ", ";
    }
    std::cout << " ]" << std::endl;
  }
  std::cout << "\033[0m" << std::endl;
  std::cout << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({{1,1,1},{1,0,1},{1,1,1}}, {{1,0,1},{0,0,0},{1,0,1}});
  testSolution({{0,1,2,0},{3,4,5,2},{1,3,1,5}}, {{0,0,0,0},{0,4,5,0},{0,3,1,0}});
  testSolution({{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}}, {{0,0,3,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}});
}
