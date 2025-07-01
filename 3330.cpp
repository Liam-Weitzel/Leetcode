#include <string>

class Solution { // Jul 01, 2025
public:
  int possibleStringCount(std::string word) {
    char prev = word[0];
    int count = 0;
    for(int i = 0; i < word.length(); i++) {
      if(prev == word[i]) count++;
      else prev = word[i];
    }
    return count;
  }
};
