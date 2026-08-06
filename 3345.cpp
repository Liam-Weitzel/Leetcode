#include <functional>
#include <numeric>
#include <string>
#include <vector>

class Solution { // Aug 06, 2026
private:
  std::vector<int> getDigits(int n) {
    //this can be faster by not using string method but by using modulo & divide
    std::string s = std::to_string(n);
    std::vector<int> digits;
    for (char c : s) {
      digits.push_back(c - '0');
    }
    return digits;
  }
public:
  int smallestNumber(int n, int t) {
    //return the smallest number greater than or equal to n such that the PRODUCT of its DIGITS is divisible by t
    // n = 10
    // t = 2
    // 10 = 1*0 = 0
    // 0/2 YES
    // 
    // n = 15
    // t = 3
    // 1*5 = 5 / 3 NO
    // 1*6 = 6 / 3 YES
    //
    //is there  a smarter way to do this than just iterate from n to infinity until the condition is met?
    //HINT1: You have to check at most 10 numbers. - i don't see this
    //but assuming its true, we just do brute force
    //ah that is given that 1 <= n <= 100 & 1 <= t <= 10

    for(int i = n; i < n+10; i++) {
      std::vector<int> digits = getDigits(i);
      int product = std::accumulate(digits.begin(), digits.end(), 1, std::multiplies<int>());
      if(product%t == 0) return i;
    }

    return -1;
  }
};
