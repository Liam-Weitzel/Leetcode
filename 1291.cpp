#include <vector>

class Solution { // Jul 13, 2026
private:
  std::vector<int> getDigits(int n) {
    std::vector<int> digits;
    if (n == 0) {
      digits.push_back(0);
    } else {
      int divisor = 1;
      while (n / divisor >= 10) divisor *= 10;
      while (divisor > 0) {
        digits.push_back(n / divisor);
        n %= divisor;
        divisor /= 10;
      }
    }
    return digits;
  }

  bool isSequential(std::vector<int> digits) {
    for(int i = 1; i < digits.size(); i++)
      if(digits[i-1] != digits[i]-1)
        return false;
    return true;
  }

public:
  std::vector<int> sequentialDigits(int low, int high) {
    std::vector<int> res;
    std::vector<int> digits = getDigits(low);
    if(isSequential(digits)) res.push_back(low);

    while(low <= high) {
      digits = getDigits(low);

      if(digits.front() <= 9-digits.size() && isSequential(digits)) {
        digits.front()++;
        for (int i = 1; i < digits.size(); i++)
          digits[i] = digits[i-1]+1;
      }
      else if (digits.front() <= 10-digits.size() && !isSequential(digits)) {
        for (int i = 1; i < digits.size(); i++)
          digits[i] = digits[i-1]+1;
        
      } else {
        int newSize = digits.size() + 1;
        digits.clear();
        for(int i = 1; i <= newSize; i++)
          digits.push_back(i);
      }

      int newLow = 0;
      for (int d : digits) newLow = newLow * 10 + d;

      if(newLow <= high && newLow >= low)
        res.push_back(newLow);
      low = newLow;
    }
    
    return res;
  }
};
