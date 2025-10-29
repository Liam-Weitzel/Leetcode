#include <bitset>

class Solution { // Oct 29, 2025
public:
  int smallestNumber(int n) {
    std::bitset<16> res;
    int count = 0;
    while(res.to_ulong() < n) {
      res.set(count);
      count++;
    }
    return res.to_ulong();
  }
};
