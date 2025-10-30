#include <numeric>
#include <vector>

class Solution { // Oct 30, 2025
public:
  int minNumberOperations(std::vector<int>& target) {
    int n = target.size();
    std::vector<int> cur(n, 0);

    int t_sum = std::accumulate(target.begin(), target.end(), 0);
    int c_sum = 0;
    int ops = 0;

    while(t_sum > c_sum) {
      // do a linear scan of cur & find the first subarray which needs an increment
      int start = -1;
      int end = -1;
      for(int i = 0; i < n; i++) {
        if(cur[i] < target[i]) {
          if(start == -1) start = i;
        } else {
          if(end == -1 && start != -1) {
            end = i;
            break;
          }
        }
      }
      if(end == -1 && start != -1) end = n;

      ops++;
      // increment first subarray
      for(int i = start; i < end; i++) {
        cur[i]++;
        c_sum++;
      }
    }

    return ops;
  }
};
