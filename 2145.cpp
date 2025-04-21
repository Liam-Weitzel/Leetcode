#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

class Solution { // Apr 21, 2025
public:
  int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
    std::vector<long long> zeroDryRun(differences.size()+1);
    zeroDryRun[0] = 0;
    for(int i = 0; i < differences.size(); i++) {
      zeroDryRun[i+1] = zeroDryRun[i] + differences[i];
    }
    
    long long max = *std::max_element(zeroDryRun.begin(), zeroDryRun.end());
    long long min = *std::min_element(zeroDryRun.begin(), zeroDryRun.end());

    long long first = lower-min;
    long long last = upper-max;

    long long res = last-first+1;
    if(res < 0) return 0;
    return res;
  }
};

void testSolution(std::vector<int> differences, int lower, int upper, int expected) {
  Solution res;
  int ans = res.numberOfArrays(differences, lower, upper);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Differences: ";
  for(int i : differences) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Lower: " << lower << std::endl;
  std::cout << "Upper: " << upper << std::endl;

  std::cout << "Answer: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,-3,4}, 1, 6, 2);
  testSolution({3,-4,5,1,-2}, -4, 5, 4);
  testSolution({4,-7,2}, 3, 6, 0);
}
