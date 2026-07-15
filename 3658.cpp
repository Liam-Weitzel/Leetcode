#include <algorithm>

class Solution { // Jul 15, 2026
private:
  int sumOdd(int n) {
    int sum = 0;
    int cur = 1;
    for(int i = 0; i < n; i++) {
      sum += cur;
      cur += 2;
    }
    return sum;
  }

  int sumEven(int n) {
    int sum = 0;
    int cur = 2;
    for(int i = 0; i < n; i++) {
      sum += cur;
      cur += 2;
    }
    return sum;
  }

public:
  int gcdOfOddEvenSums(int n) {
    int a = sumOdd(n);
    int b = sumEven(n);
    int remainder = 1;
    int prevRemainder = 0;
    while(remainder != 0) {
      prevRemainder = remainder;
      remainder = std::max(a, b) % std::min(b, a);
      b = std::min(b, a);
      a = remainder;
    }
    return prevRemainder;
  }
};
