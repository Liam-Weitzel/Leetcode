#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
  int minOperations(std::vector<std::string>& logs) {
    int level = 0;
    for(std::string i : logs) {
      if(i == "../") {
        level = std::max(0, level-1);
      } else if (i == "./") {
      } else {
        level++;
      }
    }
    return level;
  }
};

void testSolution(std::vector<std::string> logs, int expected) {
  Solution res;
  int ans = res.minOperations(logs);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Logs: ";
  for(std::string i : logs) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({"d1/","d2/","../","d21/","./"}, 2);
  testSolution({"d1/","d2/","./","d3/","../","d31/"}, 3);
  testSolution({"d1/","../","../","../"}, 0);
}
