#include <cmath>
#include <iostream>
#include <map>

class Solution { // Apr 12, 2025
private:
  //An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.
  bool isGood(int x, int n, int k) {
    char buffer[64];
    sprintf(buffer, "%d" , x);

    int size = 0;
    for(char i : buffer) {
      if(i == '\0') break;
      size++;
    }

    if(size > n) return false;

    std::map<char, int> char_count;
    for(int i = 0; i < size; i++) {
      char_count[buffer[i]]++;
    }

    bool oddFound = size % 2 == 0;
    for(std::pair<char, int> i : char_count) {
      if(i.second % 2 != 0) {
        if(!oddFound) {
          oddFound = true;
        } else return false;
      }
    }

    if(x % k != 0) return false; // I think this is wrong, it should check the palindrome formed

    return true;
  }

public:
  long long countGoodIntegers(int n, int k) {

    long long count = 0; // Testing isGood with bad solution
    std::cout << (std::pow(10, n)-1)*-1 << " : " << std::pow(10, n)-1 << std::endl;
    for(int i = 1; i < std::pow(10, n)-1; i++) {
      if(isGood(i, n, k)) {
        std::cout << i << std::endl;
        count++;
      }
    }

    return count;
  }
};

void testSolution(int n, int k, long long expected) {
  Solution res;
  int ans = res.countGoodIntegers(n, k);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "N, K: " << n << ", " << k << std::endl;

  std::cout << "Output: " << ans << std::endl;;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(3, 5, 27);
  testSolution(1, 4, 2);
  testSolution(5, 6, 2468);
}
