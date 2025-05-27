#include <iostream>

class Solution {
public:
  int differenceOfSums(int n, int m) {
    /* num1: The sum of all integers in the range [1, n] (both inclusive) that are not divisible by m.
       num2: The sum of all integers in the range [1, n] (both inclusive) that are divisible by m.
       Return the integer num1 - num2. */

    //O(N) O(1) is obvious... im sure there is a math way

    int num1 = 0;
    int num2 = 0;
    for(int i = 1; i <= n; i++) {
      if(i % m != 0) num1 += i;
      else num2 += i;
    }

    return num1 - num2;
  }
};

void testSolution(int n, int m, int expected) {
  Solution res;
  int ans = res.differenceOfSums(n, m);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "N: " << n << ", M: " << m << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;

  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(10,3,19);
  testSolution(5,6,15);
  testSolution(5,1,-15);
}
