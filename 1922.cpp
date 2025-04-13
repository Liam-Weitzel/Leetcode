#include <cmath>
#include <iostream>
#include <set>
#include <string>

class Solution { // Apr 13, 2025
private:
  const std::set<int> primes = {2,3,5,7};
  const int MOD = 1e9 + 7;

  bool isGood(std::string num) {
    for(int i = 0; i < num.size(); i++) {
      int digit = num[i] - '0';
      if(i%2==0) {
        if(digit%2!=0) return false;
      } else {
        if(!primes.count(digit)) return false;
      }
    }
    return true;
  }

  int bruteForce(long long n) {
    int count = 0;

    for(int i = 0; i < std::pow(10, n); i++) {
      if(isGood(std::to_string(i))) {
        std::cout << i << std::endl;
        count++;
      }
    }
    return count;
  }

  int ON(long long n) {
    long long count = 5;
    for (long long i = 2; i <= n; ++i) {
      if (i % 2 == 0) count = (count * 4) % MOD;
      else count = (count * 5) % MOD;
    }
    return count;
  }

  long long modpow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
      if (exp % 2) res = (res * base) % mod;
      base = (base * base) % mod;
      exp /= 2;
    }
    return res;
  }

  int OLogN(long long n) {
    long long odd = (n + 1) / 2;
    long long even = n / 2;
    return (modpow(5, odd, MOD) * modpow(4, even, MOD)) % MOD;
  }

public:
  int countGoodNumbers(long long n) {
    return OLogN(n);
  }
};

void testSolution(long long n, int expected) {
  Solution res;
  int ans = res.countGoodNumbers(n);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "N: " << n << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(1, 5);
  testSolution(4, 400);
  testSolution(50, 564908303);
}
