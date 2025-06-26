#include <string>

class Solution { // Jun 26, 2025
private:
  int bitValue(int nBits, int index) {
    return 1 << (nBits - index - 1);
  }

public:
  int longestSubsequence(std::string s, int k) {
    int size = s.size();
    int res = size;
    int curr = std::stoi(s, nullptr, 2);
    int first1 = s.find('1');
    while(curr > k) {
      curr -= bitValue(size, first1);
      first1 = s.find('1', first1+1);
      res--;
    }
    return res;
  }
};
