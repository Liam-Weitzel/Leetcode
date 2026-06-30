#include <map>
#include <string>

class Solution { // Jun 30, 2026
public:
  int numberOfSubstrings(std::string s) {
    // For each position we simply need to find the first occurrence of a/b/c on or after this position.
    // So we can pre-compute three link-list of indices of each a, b, and c.
    // Then do a sliding window
    // If we have a match we take the start of the match + any remaining chars as permutations as they will all ALWAYS be valid
    // so max window size is if we have an A, B, and C, then we increment left pointer...

    //abcabc
    //a, l = 0, r = 0
    //ab, l = 0, r = 1
    //abc, l = 0, r = 2 (MATCH) res = 4
    //bc, l = 1, r = 2
    //bca, l = 1, r = 3 (MATCH) res = 4 + 3 = 7
    //ca, l = 2, r = 3
    //cab, l = 2, r = 4 (MATCH) res = 4 + 3 + 2 = 9
    //ab, l = 3, r = 4
    //abc, l = 3, r = 5 (MATCH) res = 4 + 3 + 2 + 1 = 10
    //bc, l = 4, r = 5
    //c, l = 5, r = 5

    //we can optimize this using linkedlist but lets try without first

    //aaacb
    //a, l = 0, r = 0
    //aa, l = 0, r = 1
    //aaa, l = 0, r = 2
    //aaac, l = 0, r = 3
    //aaacb, l = 0, r = 4 (MATCH) res = 1
    //aacb, l = 1, r = 4 (MATCH) res = 2
    //acb, l = 2, r = 4 (MATCH) res = 3
    //cb, l = 3, r = 4
    //b, l = 4, r = 4

    int r = 0, l = 0;
    std::map<char, int> found;
    int res = 0;
    found[s[r]]++;
    while(r < s.size() || l < s.size()) {
      bool match = found['a'] && found['b'] && found['c'];
      if(match) {
        found[s[l]]--;
        l++;
        res += s.size() - r;
      } else {
        if(r < s.size() - 1) {
          r++;
          found[s[r]]++;
        }
        else break;
      }

    }
    return res;
  };
};
