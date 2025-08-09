class Solution {
public:
  bool isPowerOfTwo(int n) { // Aug 09, 2025
    return (n > 0) && ((n & (n - 1)) == 0);
  }
};
