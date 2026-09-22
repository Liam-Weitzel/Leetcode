#include <vector>
#include <algorithm>

class Solution { // Sep 22, 2026
public:
  int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
    int res = duration; //last poison
    for(int i = 1; i < timeSeries.size(); ++i)
      res += std::min(duration, timeSeries[i]-timeSeries[i-1]);
    return res;
  }
};
