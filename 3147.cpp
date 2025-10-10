#include <algorithm>
#include <vector>

class Solution { // Oct 10, 2025
public:
  int maximumEnergy(std::vector<int>& energy, int k) {
    std::vector<int> dp(energy.size(), 0);
    for(int i = energy.size()-1; i >= 0; i--) {
      if(i + k < energy.size()) {
        dp[i] = energy[i] + dp[i + k];
      } else {
        dp[i] = energy[i];
      }
    }
    return *std::max_element(dp.begin(), dp.end());
  }
};
