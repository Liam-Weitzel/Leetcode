#include <string>

class Solution { // Sep 20, 2026
public:
  int reverseDegree(std::string s) {
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
      sum += (26 - (s[i] - 'a')) * (i + 1);
    return sum;
  }
};
