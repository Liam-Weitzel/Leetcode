#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>

class Solution { //Jul 12, 2024
private:
  int maximumGainHelper(std::string& s, std::stack<char>& eraseStack, int& res, std::pair<std::string, int>& pattern) {
    for(char i : s) {
      if(eraseStack.size() == 0) {
        eraseStack.push(i);
      } else if(std::string() + eraseStack.top() + i == pattern.first) {
        res+=pattern.second;
        eraseStack.pop();
      } else {
        eraseStack.push(i);
      }
    }
    return res;
  }

public:
  int maximumGain(std::string s, int x, int y) {
    int res = 0;
    std::stack<char> eraseStack;

    std::pair<std::string, int> optimal = (x > y ? std::make_pair("ab", x) : std::make_pair("ba", y));
    maximumGainHelper(s, eraseStack, res, optimal);

    s.clear();
    while(!eraseStack.empty()) {
      s.push_back(eraseStack.top());
      eraseStack.pop();
    }
    std::reverse(s.begin(), s.end());

    std::pair<std::string, int> subOptimal = (x <= y ? std::make_pair("ab", x) : std::make_pair("ba", y));
    maximumGainHelper(s, eraseStack, res, subOptimal);

    return res;
  }
};

void testSolution(std::string s, int x, int y, int expected) {
  Solution res;
  int ans = res.maximumGain(s, x, y);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "S: " << s << std::endl;
  std::cout << "X,Y: " << x << ", " << y << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("cdbcbbaaabab", 4, 5, 19);
  testSolution("aabbaaxybbaabb", 5, 4, 20);
}
