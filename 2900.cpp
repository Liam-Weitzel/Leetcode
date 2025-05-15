#include <cstdint>
#include <iostream>
#include <vector>

class Solution { // May 15, 2025
public:
  std::vector<std::string> getLongestSubsequence(std::vector<std::string>& words, std::vector<int>& groups) {
    std::vector<std::string> longestSubsequence;
    uint8_t lastAppendedGroup = 2;

    for(int i = 0; i < words.size(); i++) {
      if(lastAppendedGroup != groups[i]) {
        longestSubsequence.push_back(words[i]);
        lastAppendedGroup = groups[i];
      }
    }

    return longestSubsequence;
  }
};

void testSolution(std::vector<std::string> words, std::vector<int> groups, std::vector<std::string> expected) {
  Solution res;
  std::vector<std::string> ans = res.getLongestSubsequence(words, groups);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Words: ";
  for(std::string i : words) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Groups: ";
  for(int i : groups) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: ";
  for(std::string i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(std::string i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({"e","a","b"}, {0,0,1}, {"e","b"});
  testSolution({"a","b","c","d"}, {1,0,1,1}, {"a","b","c"});
}
