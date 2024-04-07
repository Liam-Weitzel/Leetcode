#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <string>

class Solution { // Apr 07, 2024
public:
  bool checkValidString(std::string s) {
    int stack = 0;
    int wildCards = 0;
    int minStack = INT_MAX;

    for(char i : s) {
      if(i == ')') stack--;
      if(i == '(') stack++;
      if(i == '*') wildCards++;
      minStack = std::min(minStack, stack);
    }

    while((stack != 0 || minStack != 0) && wildCards != 0) {
      if(stack < 0 || minStack < 0) {
        auto pos = s.find('*');
        s[pos] = '(';
        stack++;
        if(minStack < 0) minStack++;
      } else if (stack > 0) {
        auto pos = s.rfind('*');
        s[pos] = ')';
        stack--;
      }
      wildCards--;
    }

    minStack = INT_MAX;
    stack = 0;
    for(int i = 0; i < s.length(); ++i) {
      if(s[i] == ')') stack--;
      if(s[i] == '(') stack++;
      minStack = std::min(minStack, stack);
    }

    return minStack == 0 && stack == 0;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->checkValidString("(*))") << std::endl;
  return 0;
}
