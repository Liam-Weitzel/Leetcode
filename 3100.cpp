#include <algorithm>

class Solution { // Oct 02, 2025
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int numEmptyBottles = 0;
    int res = 0;
    while(numBottles >= numExchange) {
      numEmptyBottles += std::min(numBottles, numExchange);
      numBottles -= numEmptyBottles;
      res += numEmptyBottles;
      if(numEmptyBottles >= numExchange) {
        numBottles += 1;
        numExchange += 1;
        numEmptyBottles = 0;
      }
    }
    res += numBottles;
    return res;
  }
};
