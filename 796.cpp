#include <string>

class Solution { // Jul 21, 2026
public:
  bool rotateString(std::string s, std::string goal) {
    // Given two strings 's' and 'goal', return 'true' if and only if 's' can become 'goal' after some number of shifts on 's'.
    // A shift on 's' consists of moving the leftmost character of 's' to the rightmost position.
    // Ok so we need to check if you can 'rotate' the string 's' to become 'goal'.

    if (s.size() != goal.size()) return false;
    std::string duplicated = s;
    duplicated.append(s);
    return duplicated.find(goal) != std::string::npos;
  }
};
