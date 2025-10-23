#include <string>

class Solution { // Oct 23, 2025
public:
  bool hasSameDigits(std::string s) {
    while(s.size() > 2) {
      for(int i = 0; i < s.size()-1; i++) {
        s[i] = (((s[i]-'0') + (s[i+1]-'0'))%10)+'0';
      }
      s.erase(s.size()-1, 1);
    }
    return s[0]==s[1];
  }
};
