#include <cstdlib>
#include <string>

class Solution { // Jul 07, 2026
public:
  long long sumAndMultiply(int n) {
    std::string s = std::to_string(n);
    long long sum = 0;
    std::string x;
    for(char i : s) {
      if(i != '0') {
        x += i;
        sum += i - '0';
      }
    }
    if(x == "") x = "0";
    return std::atoi(x.c_str()) * sum;
  }
};
