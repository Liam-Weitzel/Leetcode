#include <vector>

class Solution { // Aug 08, 2025
  double dfs(std::vector<std::pair<int, int>>& operations, std::pair<int, int>& i, int A, int B) {
    A -= i.first;
    B -= i.second;
    if(A <= 0 && B <= 0) return 0.5;
    if(A <= 0) return 1;
    if(B <= 0) return 0;

    double res = 0;
    for(std::pair<int, int> j : operations) {
      res += dfs(operations, j, A, B)*0.25;
    }

    return res;
  }
public:
  double soupServings(int n) {
    if(n >= 4800) return 1;
    std::vector<std::pair<int, int>> operations = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    int A = n;
    int B = n;
    double res = 0;
    for(std::pair<int, int> i : operations) {
      res += dfs(operations, i, A, B)*0.25;
    }
    return res;
  }
};
