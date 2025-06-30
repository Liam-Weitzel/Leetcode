#include <climits>
#include <map>
#include <vector>

class Solution { // Jun 30, 2025
public:
  int findLHS(std::vector<int>& nums) {
    std::map<int, int> freqMap;
    for (int i : nums) freqMap[i]++;
    int selected = INT_MIN;
    bool found = false;

    for (auto [k, v] : freqMap) {
      if (freqMap.contains(k + 1) &&
          freqMap[selected] + freqMap[selected + 1] < freqMap[k + 1] + v) {
        selected = k;
        found = true;
      }
    }

    if(!found) return 0;
    return freqMap[selected] + freqMap[selected+1];
  }
};
