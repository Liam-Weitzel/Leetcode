#include <algorithm>
#include <cmath>
#include <vector>

class Solution { // Aug 26, 2025
public:
  int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
    float longestDiagonal = 0;
    int areaOfLongest = 0;
    for(std::vector<int> i : dimensions) {
      float diagonal = std::sqrt(std::pow(i[0], 2) + std::pow(i[1], 2));
      if(diagonal > longestDiagonal) {
        longestDiagonal = diagonal;
        areaOfLongest = i[0] * i[1];
      }
      else if(diagonal == longestDiagonal) {
        areaOfLongest = std::max(areaOfLongest, i[0] * i[1]);
      }
    }
    return areaOfLongest;
  }
};
