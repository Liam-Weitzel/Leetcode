#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Solution { // Dec 05, 2024
public:
  bool canChange(std::string start, std::string target) {
    std::string startWithoutUnder = std::regex_replace(start, std::regex("_"), "");
    std::string targetWithoutUnder = std::regex_replace(target, std::regex("_"), "");
    for(int i = 0; i < startWithoutUnder.length(); i++) {
      if(startWithoutUnder[i] != targetWithoutUnder[i]) return false;
    }

    std::vector<u_short> startLefts(start.length());
    std::vector<u_short> startRights(start.length());

    u_short rCount = 0, lCount = 0;
    for(int i = 0; i < start.length(); i++) {
      if(start[i] == 'R') rCount++;
      startRights[i] = rCount;
    }
    std::cout << std::endl;
    for(int i = start.length()-1; i >= 0; i--) {
      if(start[i] == 'L') lCount++;
      startLefts[i] = lCount;
    }
    std::reverse(startLefts.begin(), startLefts.end());

    std::vector<u_short> targetLefts(target.length());
    std::vector<u_short> targetRights(target.length());

    rCount = 0, lCount = 0;
    for(int i = 0; i < target.length(); i++) {
      if(target[i] == 'R') rCount++;
      targetRights[i] = rCount;
    }
    for(int i = target.length()-1; i >= 0; i--) {
      if(target[i] == 'L') lCount++;
      targetLefts[i] = lCount;
    }
    std::reverse(targetLefts.begin(), targetLefts.end());

    for(int i = 0; i < start.length(); i++) {
      if(targetLefts[i] > startLefts[i]) return false;
      if(targetRights[i] > startRights[i]) return false;
    }

    return true;
  }
};

void testSolution(std::string start, std::string target, bool expected) {
  Solution res;
  int ans = res.canChange(start, target);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Start: " << start << std::endl;
  std::cout << "Target: " << target << std::endl;

  std::cout << "Output: " << ans << std::endl << std::endl;
  std::cout << "Expected: " << expected << std::endl << std::endl;
  std::cout << "-------------------------" << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("_L__R__R_", "L______RR", true);
  testSolution("R_L_", "__LR", false);
  testSolution("_R", "R_", false);
}
