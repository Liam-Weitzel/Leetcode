#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Solution { // Apr 05, 2024
private:
  bool isStringGood(std::string& s, std::vector<int>& toRemove) {
    char prevChar = ' ';
    bool res = true;
    for(int i = 0; i < s.length(); ++i) {
      if(prevChar == s[i] + 32 || prevChar == s[i] - 32) { //32 = ascii code diff between lower case and uppercase
        toRemove.push_back(i-1);
        toRemove.push_back(i);
        i++;
        res = false;
      }
      prevChar = s[i];
    }
    return res;
  }

public:
  std::string makeGood(std::string s) {
    std::vector<int> toRemove;
    while(!isStringGood(s, toRemove)) {
      for(int i = toRemove.size()-1; i >= 0; --i) {
        std::cout << i << ":" << toRemove[i] << std::endl;
        s.erase(toRemove[i],1);
      }
      toRemove.clear();
    }
    return s;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->makeGood("leEeetcode") << std::endl;
  return 0;
}
