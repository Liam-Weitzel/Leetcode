#include <iostream>
#include <map>
#include <string>

class Solution { // Apr 23, 2025
public:
  int countLargestGroup(int n) {
    std::map<int, int> freqMap;
    for(int i = 1; i <= n; i++) {
      std::string digits = std::to_string(i);
      int sum = 0;
      for(char j : digits) {
        sum += (int) j - '0';
      }
      freqMap[sum]++;
    }

    std::map<int, int> groups;
    for(std::pair<int, int> i : freqMap) {
      groups[i.second] += 1;
    }

    int max = 0;
    for(std::pair<int, int> i : groups) {
      if(i.first > max) max = i.first;
    }

    return groups[max];
  }
};


void testSolution(int n, int expected) {
  Solution res;
  int ans = res.countLargestGroup(n);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "N: " << n << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(13, 4);
  testSolution(2, 2);
}
