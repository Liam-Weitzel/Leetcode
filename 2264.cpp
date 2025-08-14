#include <climits>
#include <cstdio>
#include <string>

class Solution {
public:
  std::string largestGoodInteger(std::string num) {
    std::string maxStr = "";
    for (int i = 0; i <= num.size() - 3; ++i) {
      if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
        std::string triplet = num.substr(i, 3);
        if (triplet > maxStr) {
          maxStr = triplet;
        }
      }
    }
    return maxStr;
  }
};

