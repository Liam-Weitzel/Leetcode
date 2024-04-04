#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

class Solution { // Apr 04, 2024
public:
  int maxDepth(std::string s) {
    int currNest = 0;
    int maxNest = 0;

    for(char i : s) {
       maxNest = std::max(currNest, maxNest);
       if(i == '(') currNest++;
       else if(i == ')') currNest--;
    }

    return maxNest;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->maxDepth("(1+(2*3)+((8)/4))+1") << std::endl;
  return 0;
}
