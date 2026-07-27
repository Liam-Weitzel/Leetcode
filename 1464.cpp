#include <climits>
#include <vector>

class Solution { // Jul 27, 2026
public:
  int maxProduct(std::vector<int>& nums) {
    int one = INT_MIN;
    int two = INT_MIN;
    for(int i : nums) {
      if(i >= one) {
        two = one;
        one = i;
      } else if(i >= two) {
        two = i;
      }
    }
    return (one-1) * (two-1);
  }
};
