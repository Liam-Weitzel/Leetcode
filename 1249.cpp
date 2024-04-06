#include <iostream>
#include <memory>
#include <string>

class Solution { // Apr 06, 2024
public:
  std::string minRemoveToMakeValid(std::string s) {
    int stack = 0;
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] == ')') stack--;
      if(s[i] == '(') stack++;
      if(stack < 0) { s[i] = '-'; stack++; }
    }
    
    while(stack != 0) {
      if(stack < 0) {
        auto pos = s.rfind(')');
        s[pos] = '-'; 
        stack++;
      } else if (stack > 0) {
        auto pos = s.rfind('(');
        s[pos] = '-';
        stack--;
      }
    }

    s.erase(std::remove(s.begin(), s.end(), '-'), s.end());

    return s;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->minRemoveToMakeValid("lee(t(c)o)de)") << std::endl;
  return 0;
}
