#include <algorithm>
#include <numeric>
#include <vector>

class Solution { // Jul 24, 2026
public:
  int arraySign(std::vector<int>& nums) {
    // I know we can do this in one pass but i'm practicing the STL
    int countNegative = std::count_if(nums.begin(), nums.end(), [](int x) { return x < 0; });
    int countZero = std::count_if(nums.begin(), nums.end(), [](int x) { return x == 0; });
    if(countZero > 0) return 0;
    if(countNegative % 2 != 0) return -1;
    return 1;
  }
  int arraySignBruteForce(std::vector<int>& nums) {
    long long product = std::accumulate(nums.begin(), nums.end(), 1LL, std::multiplies<long long>());
    if(product < 0) return -1;
    if(product > 0) return 1;
    return 0;
  }
};
