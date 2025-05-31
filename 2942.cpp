#include <iostream>
#include <vector>

class Solution { // May 24, 2025
public:
  std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
    std::vector<int> res;
    for(int i = 0; i < words.size(); i++) {
      if(words[i].find(x) != std::string::npos) res.push_back(i);
    }
    return res;
  }
};

void testSolution(std::vector<std::string> words, char x, std::vector<int> expected) {
  Solution res;
  std::vector<int> ans = res.findWordsContaining(words, x);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Words: ";
  for(std::string i : words) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "X: " << x << std::endl;

  std::cout << "Output: ";
  for(int i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({"leet","code"}, 'e', {0,1});
  testSolution({"abc","bcd","aaaa","cbc"}, 'a', {0,2});
  testSolution({"abc","bcd","aaaa","cbc"}, 'z', {});
}
