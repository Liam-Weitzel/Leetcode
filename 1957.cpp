/* #include <string>

class Solution { // Jul 21, 2025
public:
  std::string makeFancyString(std::string s) {
    int consecutiveCount = 0;
    char prevChar = '0';
    for (auto it = s.begin(); it != s.end(); ) {
      if(*it == prevChar) {
        if(consecutiveCount == 2) {
          it = s.erase(it); // this is very slow... o(N*N)
        } else {
          consecutiveCount++;
          ++it;
        }
      } else {
        prevChar = *it;
        consecutiveCount = 1;
        ++it;
      }
    }
    return s;
  }
};
*/

#include <string>

class Solution { // Jul 21, 2025
public:
  std::string makeFancyString(std::string s) {
    std::string result;
    for (char c : s) {
      if (result.size() >= 2 && result.back() == c && result[result.size() - 2] == c) {
        continue;
      }
      result.push_back(c);
    }
    return result;
  }
};
