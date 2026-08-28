#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

class Solution { // Aug 28, 2026
public:
  bool checkDivisibility(int n) {
    // You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
    //     The digit sum of n (the sum of its digits).
    //     The digit product of n (the product of its digits).
    // Return true if n is divisible by this sum; otherwise, return false.
    int nCopy = n;
    std::vector<int> digits;
    while(nCopy > 0) {
      digits.push_back(nCopy%10);
      nCopy /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    int product = std::accumulate(digits.begin(), digits.end(), 1, std::multiplies<int>());
    int sum = std::accumulate(digits.begin(), digits.end(), 0);
    std::cout << product << " " << sum << " " << n << std::endl;
    return n % (product + sum) == 0;
  }
};
