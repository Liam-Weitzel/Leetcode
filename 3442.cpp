#include <climits>
#include <iostream>
#include <vector>

class Solution { // Jun 10, 2025
public:
  int maxDifference(std::string s) {
    std::vector<int> freqMap(26);
    for(char i : s) freqMap[i - 'a']++;

    int highestOdd = INT_MIN;
    int lowestEven = INT_MAX;
    for(int i : freqMap) {
      if(i == 0) continue;
      else if(i % 2 == 0) lowestEven = std::min(lowestEven, i);
      else highestOdd = std::max(highestOdd, i);
    }

    return highestOdd - lowestEven;
  }
};

void testSolution(std::string s, int expected) {
  Solution res;
  int ans = res.maxDifference(s);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "S: " << s << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("aaaaabbc", 3);
  testSolution("abcabcab", 1);
}
