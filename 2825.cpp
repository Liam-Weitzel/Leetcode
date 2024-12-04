#include <iostream>
#include <string>

class Solution { // Dec 04, 2024
public:
  bool canMakeSubsequence(std::string str1, std::string str2) {
    std::string str1_operated;
    str1_operated.resize(str1.length());

    for(int i = 0; i < str1.length(); i++) {
      str1_operated[i] = str1[i] + 1;
      if(str1[i] == 'z') str1_operated[i] = 'a';
    }

    int ptr = 0;
    for(int i = 0; i < str1.length(); i++) {
      if(str2[ptr] == str1[i] || str2[ptr] == str1_operated[i]) ptr++;
    }

    return ptr == str2.length();
  }
};

void testSolution(std::string str1, std::string str2, bool expected) {
  Solution res;
  bool ans = res.canMakeSubsequence(str1, str2);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Str1: " << str1 << std::endl;
  std::cout << "Str2: " << str2 << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;

  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("abc", "ad", true);
  testSolution("zc", "ad", true);
  testSolution("ab", "d", false);
}
