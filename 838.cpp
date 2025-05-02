#include <climits>
#include <iostream>
#include <string>
#include <vector>

class Solution { // May 02, 2025
public:
  std::string pushDominoes(std::string dominoes) {
    int n = dominoes.length();
    std::vector<int> leftPass(n);
    int forceCounter = 0;
    for(int i = 0; i < n; i++) {
      if(dominoes[i] == 'L') forceCounter = 0;
      else if(dominoes[i] == 'R') forceCounter = INT_MAX;
      else {
        forceCounter--;
        forceCounter = std::max(0, forceCounter);
      }
      leftPass[i] = forceCounter;
    }

    std::vector<int> rightPass(n);
    forceCounter = 0;
    for(int i = n-1; i >= 0; i--) {
      if(dominoes[i] == 'R') forceCounter = 0;
      else if(dominoes[i] == 'L') forceCounter = INT_MAX;
      else {
        forceCounter--;
        forceCounter = std::max(0, forceCounter);
      }
      rightPass[i] = forceCounter;
    }

    // std::cout << "leftpass: ";
    // for(int i : leftPass) std::cout << i << ", ";
    // std::cout << std::endl;
    // std::cout << "rightpass: ";
    // for(int i : rightPass) std::cout << i << ", ";
    // std::cout << std::endl;

    std::string res = "";
    for(int i = 0; i < n; i++) {
      if(leftPass[i] == rightPass[i]) res.push_back('.');
      else res.push_back(leftPass[i] > rightPass[i] ? 'R' : 'L');
    }

    return res;
  }
};

void testSolution(std::string dominoes, std::string expected) {
  Solution res;
  std::string ans = res.pushDominoes(dominoes);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Dominoes: " << dominoes << std::endl;
  std::cout << "Output: " << ans << std::endl;
  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("RR.L", "RR.L");
  testSolution(".L.R...LR..L..", "LL.RR.LLRRLL..");
}
