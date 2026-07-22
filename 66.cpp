#include <vector>

class Solution { // Jul 22, 2026
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    int cur = digits.size()-1;
    bool carry = true;
    while(cur >= 0) {
      digits[cur] += (carry ? 1 : 0);
      carry = false;
      if(digits[cur] >= 10) {
        carry = true;
        digits[cur] -= 10;
      }
      cur--;
    }
    if(carry) digits.insert(digits.begin(), 1);
    return digits;
  }
};
