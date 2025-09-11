#include <algorithm>
#include <set>
#include <string>
#include <vector>

class Solution { // Sep 11, 2025
public:
  std::string sortVowels(std::string s) {
    std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    std::vector<char> vowelSet;
    std::vector<int> vowelPos;

    for(int i = 0; i < s.size(); i++) {
      if(vowels.find(s[i]) != vowels.end()) {
        vowelPos.push_back(i);
        vowelSet.push_back(s[i]);
      }
    }

    std::sort(vowelSet.begin(), vowelSet.end(), std::less());

    for(int i = 0; i < vowelSet.size(); i++) {
      s[vowelPos[i]] = vowelSet[i];
    }

    return s;
  }
};
