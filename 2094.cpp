#include <iostream>
#include <unordered_map>
#include <vector>

class Solution { // May 12, 2025
public:
  std::vector<int> findEvenNumbers(std::vector<int>& digits) {
    std::unordered_map<int, int> digitsFreq;
    for(int i : digits) digitsFreq[i]++;
    std::unordered_map<int, int> digitsFreqCopy = digitsFreq;

    std::vector<int> ans;

    for(int i = 100; i <= 998; i += 2) {
      int cur = i;
      int digitsAdded = 0;
      std::vector<int> num;
      while (cur > 0) {
        num.push_back(cur % 10); // get last digit

        if(digitsFreqCopy[num.back()] > 0) {
          digitsFreqCopy[num.back()]--;
          digitsAdded++;
        } else {
          break;
        }

        cur /= 10;               // remove last digit
      }

      if(digitsAdded == 3) ans.push_back(i);
      digitsFreqCopy = digitsFreq;
    }

    return ans;
  }
};

void testSolution(std::vector<int> digits, std::vector<int> expected) {
  Solution res;
  std::vector<int> ans = res.findEvenNumbers(digits);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Digits: ";
  for(int i : digits) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Answer: ";
  for(int i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({2,1,3,0}, {102,120,130,132,210,230,302,310,312,320});
  testSolution({2,2,8,8,2}, {222,228,282,288,822,828,882});
  testSolution({3,7,5}, {});
}
