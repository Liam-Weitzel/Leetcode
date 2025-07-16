#include <vector>

class Solution { // Jul 16, 2025
public:
  int maximumLength(std::vector<int>& nums) {
    //4 cases: whole array is even, or whole array is odd, or whole array is even odd alternating, or whole array is odd even alternating
    int allEvenCount = 0, allOddCount = 0, curEvenOdd = 0, curOddEven = 0;

    for (int i = 0; i < nums.size(); ++i) {
      int isEven = nums[i] % 2 == 0;

      // Count all evens and odds
      allEvenCount += isEven;
      allOddCount += !isEven;

      // For even-odd pattern
      if (curEvenOdd % 2 == 0) {
        if (isEven) curEvenOdd++;
      } else {
        if (!isEven) curEvenOdd++;
      }

      // For odd-even pattern
      if (curOddEven % 2 == 0) {
        if (!isEven) curOddEven++;
      } else {
        if (isEven) curOddEven++;
      }
    }

    return std::max({allEvenCount, allOddCount, curEvenOdd, curOddEven});
  }
};
