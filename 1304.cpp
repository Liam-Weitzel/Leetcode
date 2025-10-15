#include <vector>

class Solution { // Sep 07, 2025
public:
  std::vector<int> sumZero(int n) {
    std::vector<int> res;
    res.reserve(n);
    if(n % 2 != 0) res.push_back(0);
    int curr = 1;
    bool add = false;
    for(int i = res.size(); i < n; i++) {
      res.push_back(curr);
      if(add) {
        curr *= -1;
        curr++;
        add = false;
      }
      else {
        curr *= -1;
        add = true;
      }
    }
    return res;
  }
};
