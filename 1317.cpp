#include <vector>
#include <string>

class Solution { // Sep 08, 2025
private:
  bool isNoZero(int n) {
    std::string str = std::to_string(n);
    for (char c : str) {
      if (c == '0') return false;
    }
    return true;
  }

public:
  std::vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n / 2; i++) {
      if (isNoZero(i) && isNoZero(n - i)) {
        return {i, n - i};
      }
    }
    return {};
  }
};
