#include <iostream>

class Solution { // Jul 06, 2024
public:
  int passThePillow(int n, int time) {
    if(n == 1) return 1;
    int currTime = 1;
    int currPerson = 1;
    int incrementor = 1;
    while(currTime <= time) {
      if(time-currTime >= (n-1)*2) {
        currTime += (n-1)*2;
      } else {
        currTime++;
        currPerson += incrementor;
        if(currPerson == n || currPerson == 1) incrementor *= -1;
      }
    }

    return currPerson;
  }
};

void testSolution(int n, int time, int expected) {
  Solution res;
  int ans = res.passThePillow(n, time);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "N: " << n << std::endl;
  std::cout << "Time: " << time << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(4, 5, 2);
  testSolution(3, 2, 3);
  testSolution(12, 2, 3);
  testSolution(1, 2, 1);
  testSolution(3, 4, 1);
  testSolution(18, 38, 5);
  testSolution(18, 30, 5);
  testSolution(2, 341, 2);
}

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18
// 17+17+4
// 18+18
