#include <iostream>
#include <sstream>
#include <string>

class Solution { // Apr 18, 2025
private:
  std::string RLE(std::string n) {
    std::stringstream res;

    char prev = *n.begin();
    int count = 1;

    for (auto it = std::next(n.begin()); it != n.end(); ++it) {
      char i = *it;
      if(i == prev) {
        count++;
      } else {
        res << count << prev;
        prev = i;
        count = 1;
      }
    }
    res << count << prev;

    return res.str();
  }

public:
  std::string countAndSay(int n) {
    std::string prev = "1";

    for(int i = 1; i < n; i++) {
      prev = RLE(prev);
    }

    return prev;
  }
};
;

void testSolution(int n, std::string expected) {
  Solution res;
  std::string ans = res.countAndSay(n);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "N: " << n << std::endl;

  std::cout << "Ans: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(4, "1211");
  testSolution(1, "1");
}
