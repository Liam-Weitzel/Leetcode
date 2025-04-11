#include <climits>
#include <cstdlib>
#include <iostream>

class Solution { // Apr 11, 2025
private:
  bool isSymmetric(int x) {
    char buffer[64];
    sprintf(buffer, "%d" , x);

    int size = 0;
    for(char i : buffer) {
      if(i == '\0') break;
      size++;
    }

    if(size%2!=0) return false;

    int lSum = 0;
    for(int i = 0; i < size/2; i++) {
      lSum += buffer[i] - '0';
    }

    int rSum = 0;
    for(int i = size/2; i < size; i++) {
      rSum += buffer[i] - '0';
    }

    // std::cout << "x: " << x << ", size: " << size << ", lSum: " << lSum << ", rSum: " << rSum << std::endl;

    return lSum == rSum;
  }

public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for(int i = low; i <= high; i++) {
      count += isSymmetric(i);
    }
    return count;
  }
};

void testSolution(int low, int high, int expected) {
  Solution res;
  int ans = res.countSymmetricIntegers(low, high);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Low: " << low << std::endl;
  std::cout << "High: " << high << std::endl;

  std::cout << "Answer: " << ans  << std::endl;

  std::cout << "Expected: " << expected  << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(1, 100, 9);
  testSolution(1200, 1230, 4);
}
