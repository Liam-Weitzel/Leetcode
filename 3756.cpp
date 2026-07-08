#include <string>
#include <vector>

class Solution { // Jul 08, 2026

  //Bruteforce idea: loop over 3754 solution for each query. I think there is a O(N) or O(NlogN) approach
  //Not enough time in commute

  private:
    static constexpr long long MODULO = 1 000000007LL;

  public:
    std::vector<int> sumAndMultiply(std::string s, std::vector<std::vector<int>>& queries) {
      std::vector<int> res(queries.size());

      for (int query = 0; query < queries.size(); query++) {
        int l = queries[query][0];
        int r = queries[query][1];

        long long number = 0;
        long long sum = 0;

        for (int i = l; i <= r; i++) {
          if (s[i] != '0') {
            int digit = s[i] - '0';
            number = (number * 10 + digit) % MODULO;
            sum += digit;
          }
        }

        res[query] = (number * (sum % MODULO)) % MODULO;
      }

      return res;
    }
};
