#include <set>
#include <string>

class Solution {
public:
  bool doesAliceWin(std::string s) {
    std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for(char i : s) if(vowels.find(i) != vowels.end()) return true;
    return false;
  }
};
