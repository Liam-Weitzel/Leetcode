#include <algorithm>
#include <vector>

class Solution { // Jul 25, 2026
public:
  int maxProduct(int n) {
    // maximum product = the highest numbers multiplied by each other...
    std::vector<int> nVec;
    while(n > 0) {
      int cur = n % 10;
      nVec.push_back(cur);
      n /= 10;
    }
    auto oneIter = std::max_element(nVec.begin(), nVec.end());
    int one = *oneIter;
    nVec.erase(oneIter);
    int two = *std::max_element(nVec.begin(), nVec.end());
    return one * two;
  }
};
