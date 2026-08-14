#include <algorithm>
#include <string>

class Solution { // Aug 14, 2026
public:
  int maximumLengthSubstring(std::string s) {
    int max = 0;
    int map[26] = {};
    int left = 0;
    for(int right = 0; right < s.size(); right++) {
      char rightChar = s[right];
      int rightCharIndex = rightChar-'a';
      map[rightCharIndex]++;
      while(map[rightCharIndex] > 2) {
        char leftChar = s[left];
        int leftCharIndex = leftChar-'a';
        map[leftCharIndex]--;
        left++;
      }
      max = std::max(right-left+1, max);
    }
    return max;
  }
};
