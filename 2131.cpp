#include <iostream>
#include <map>
#include <utility>
#include <vector>

class Solution { // May 25, 2025
public:
  int longestPalindrome(std::vector<std::string>& words) {
    std::map<std::pair<char, char>, int> palindromic;
    std::map<std::pair<char, char>, int> nonPalindromic;
    int count = 0;

    for(std::string i : words) {
      std::pair<char, char> p = std::make_pair(i[0], i[1]);
      if(p.first == p.second) palindromic[p]++;
      else nonPalindromic[p]++;
    }

    for(std::pair<std::pair<char, char>, int> i : nonPalindromic) {
      std::pair<char, char> toMatch = std::make_pair(i.first.second, i.first.first);
      count += std::min(i.second, nonPalindromic[toMatch])*4;
      nonPalindromic[toMatch] = 0; 
      nonPalindromic[i.first] = 0;
    }

    for(std::pair<std::pair<char, char>, int> i : palindromic) {
      if(i.second >= 2) {
        count += i.second/2*4;
        palindromic[i.first] = i.second%2;
      }
    }

    for(std::pair<std::pair<char, char>, int> i : palindromic) {
      if(i.second >= 1 && i.first.first == i.first.second) {
        count += 2;
        break;
      }
    }

    return count;
  }
};

void testSolution(std::vector<std::string> words, int expected) {
  Solution res;
  long long ans = res.longestPalindrome(words);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Words: ";
  for(std::string i : words) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Answer: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({"lc","cl","gg"}, 6);
  testSolution({"ab","ty","yt","lc","cl","ab"}, 8);
  testSolution({"cc","ll","xx"}, 2);
  testSolution({"qo","fo","fq","qf","fo","ff","qq","qf","of","of","oo","of","of","qf","qf","of"}, 14);
}
