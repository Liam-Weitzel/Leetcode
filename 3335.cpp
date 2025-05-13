#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution { // May 13, 2025
public:
  int lengthAfterTransformations(std::string s, int t) {
    const int MOD = 1000000007;
    std::vector<long long> freqMap(26, 0);

    // Count initial frequencies
    for (char c : s) {
      freqMap[c - 'a']++;
    }

    // Apply transformations
    for (int i = 0; i < t; i++) {
      long long zCount = freqMap[25];  // Save 'z' count
      freqMap[25] = 0;

      // Shift all characters forward
      for (int j = 24; j >= 0; j--) {
        freqMap[j + 1] = (freqMap[j + 1] + freqMap[j]) % MOD;
        freqMap[j] = 0;
      }

      // Handle 'z' transformation to "ab"
      freqMap[0] = (freqMap[0] + zCount) % MOD;  // Add to 'a'
      freqMap[1] = (freqMap[1] + zCount) % MOD;  // Add to 'b'
    }

    // Calculate final length with modulo
    long long sum = 0;
    for (long long freq : freqMap) {
      sum = (sum + freq) % MOD;
    }

    return static_cast<int>(sum);
  }
};

void testSolution(std::string s, int t, int expected) {
  Solution res;
  int ans = res.lengthAfterTransformations(s, t);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "S: " << s << std::endl;

  std::cout << "T: " << t << std::endl;

  std::cout << "Ans: " << ans << std::endl;

  std::cout << "Epected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("abcyy", 2, 7);
  testSolution("azbk", 1, 5);
}
