#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Solution { // Mar 05, 2024
public:
  int minimumLength(std::string s) {
    std::vector<std::pair<char, int>> consecutiveS;
    char LastChar = '.';
    for(char i : s) {
      if(i == LastChar) {
        consecutiveS.back().second++;
      } else {
        consecutiveS.push_back(std::make_pair(i, 1));
      }
      LastChar = i;
    }
    
    int leftPtr = 0;
    int rightPtr = consecutiveS.size()-1;
    while(leftPtr != rightPtr) {
      if(consecutiveS[leftPtr].first == consecutiveS[rightPtr].first) {
        leftPtr++;
        rightPtr--;
      } else {
        break;
      }
    }

    if(rightPtr-leftPtr == 0 && consecutiveS[rightPtr].second > 1) return 0;

    int res = 0;
    for(int i = leftPtr; i <= rightPtr; i++) {
      res += consecutiveS[i].second;
    }
    return res;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->minimumLength("aabbccdba") << std::endl;
  return 0;
}
