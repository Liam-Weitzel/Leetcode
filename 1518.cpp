#include <iostream>

class Solution { // Oct 01, 2025
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int res = 0;
    int emptyBottles = 0;
    
    do {
      res += numBottles;
      int totalEmpty = numBottles + emptyBottles;
      numBottles = totalEmpty / numExchange;
      emptyBottles = totalEmpty % numExchange;
    } while(numBottles + emptyBottles >= numExchange);
    res += numBottles;

    return res;
  }
};

class Solution_Old { // Jul 07, 2024
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int bottlesSlurped = 0;
    int remainder = 0;

    while ( numBottles > 0 ) {
      bottlesSlurped += numBottles;
      numBottles += remainder;
      remainder = numBottles%numExchange;
      numBottles /= numExchange;
    }

    return bottlesSlurped;
  }
};

void testSolution(int numBottles, int numExchange, int expected) {
  Solution res;
  int ans = res.numWaterBottles(numBottles, numExchange);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "numBottles: " << numBottles << std::endl;
  std::cout << "numExchange: " << numExchange << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(9, 3, 13);
  testSolution(15, 4, 19);
}
