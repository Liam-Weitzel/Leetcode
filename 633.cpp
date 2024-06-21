#include <iostream>
#include <set>

class Solution { // Jun 17, 2024
public:
  bool judgeSquareSum(int c) {
    long long i = 0;
    std::set<int> sqauresSet;
    while(i*i <= c) {
      sqauresSet.insert(i*i);
      i++;
    }

    for(int j : sqauresSet) {
      if(sqauresSet.find(c - j) != sqauresSet.end()) return true;
    }

    return false;
  }
};

void testSolution(int c, bool expected) {
  Solution res;
  bool ans = res.judgeSquareSum(c);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Input: " << c << std::endl;
  std::cout << "Output: " << ans << std::endl;
  std::cout << "Expected: " << expected << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(5, true);
  testSolution(3, false);
}
