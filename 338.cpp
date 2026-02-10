#include <iostream>
#include <numeric>
#include <vector>

class Solution { // Feb 08, 2026
public:
  std::vector<int> coutingBits(int i) {
    std::vector<int> res;
    std::vector<bool> toggled(8, false);
    int powers[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    for(int j = 0; j <= i; j++) {
      if(j != 0)
        for(int pow = 0; pow < 8; pow++)
          if(j%powers[pow] == 0)
            toggled[pow] = !toggled[pow];
      res.push_back(std::accumulate(toggled.begin(), toggled.end(), 0));
    }
    return res;
  }
};

void testSolution(int i, std::vector<int> expected) {
  Solution res;
  std::vector<int> ans = res.coutingBits(i);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "I: " << i << std::endl;

  std::cout << "Ans: ";
  for(int j : ans) std::cout << j << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(int j : expected) std::cout << j << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(2, {0,1,1});
  testSolution(5, {0,1,1,2,1,2});
}
