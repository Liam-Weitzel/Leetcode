#include <vector>
#include <iostream>

class Solution { // May 11, 2025
public:
  bool threeConsecutiveOdds(std::vector<int>& arr) {
    int count = 0;
    for(int i : arr) {
      if(i % 2 != 0) count++;
      else count = 0;
      if(count == 3) return true;
    }
    return false;
  }
};

class Solution2 { // Jul 01, 2024
public:
  bool threeConsecutiveOdds(std::vector<int>& arr) {
    int oddCount = 0;
    for(int i = 0; i < arr.size(); i++) {
      if(arr[i] % 2 != 0) oddCount++;
      else oddCount=0;
      if(oddCount == 3) return true;
    }
    return false;
  }
};

void testSolution(std::vector<int> input, bool expected) {
  Solution res;
  int ans = res.threeConsecutiveOdds(input);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "input: ";
  for(int i : input) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Answer: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({2,6,4,1}, false);
  testSolution({1,2,34,3,4,5,7,23,12}, true);
}
