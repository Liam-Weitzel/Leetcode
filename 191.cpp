#include <bitset>
#include <iostream>

class Solution { // Jan 30, 2026
public:
  int hammingWeight(int n) {
    return static_cast<std::bitset<32>>(n).count();
  }
};

void testSolution(int n, int expected) {
  Solution res;
  int ans = res.hammingWeight(n);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "N: " << n << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(11, 3);
  testSolution(64, 1);
  testSolution(255, 8);
  testSolution(-3, 31);
}
