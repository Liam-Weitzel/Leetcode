#include <iostream>
#include <vector>

class Solution { // Jun 07, 2025
public:
  std::string clearStars(std::string s) {
    std::vector<char> stack;
    std::vector<int> freq(26, 0);

    for (char c : s) {
      if (c == '*') {
        int smallest = 0;
        while (freq[smallest] == 0) ++smallest;

        for (int i = stack.size() - 1; i >= 0; --i) {
          if (stack[i] == 'a' + smallest) {
            stack.erase(stack.begin() + i);
            freq[smallest]--;
            break;
          }
        }
      } else {
        stack.push_back(c);
        freq[c - 'a']++;
      }
    }

    return std::string(stack.begin(), stack.end());
  }
};

void testSolution(std::string s, std::string expected) {
  Solution res;
  std::string ans = res.clearStars(s);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "S: " << s << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;

  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("aaba*", "aab");
  testSolution("abc", "abc");
}
