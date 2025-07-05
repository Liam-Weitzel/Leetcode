#include <climits>
#include <unordered_map>
#include <vector>

class Solution { // Jul 05, 2025
public:
  int findLucky(std::vector<int>& arr) {
    std::unordered_map<int, int> freqMap;
    for(int i : arr) freqMap[i]++;

    int largestLucky = INT_MIN;
    bool found = false;
    for(std::pair<int, int> i : freqMap) {
      if(i.first == i.second && i.first > largestLucky) {
        found = true;
        largestLucky = i.first;
      }
    }

    if(found) return largestLucky;
    return -1;
  }
};
