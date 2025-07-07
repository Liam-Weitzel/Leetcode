#include <queue>
#include <set>
#include <vector>

class Solution { // Jul 07, 2025
public:
  int maxEvents(std::vector<std::vector<int>>& events) {
    auto comp = [](std::vector<int>& a, std::vector<int>& b) {
      return a[1] > b[1];
    };

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> pq(comp);

    for (std::vector<int> i : events) pq.push(i);

    int attended = 0;
    std::set<int> usedDays;
    while(!pq.empty()) {
      std::vector<int> canAttend = pq.top();
      pq.pop();
      for(int i = canAttend[0]; i <= canAttend[1]; i++) {
        if(!usedDays.contains(i)) {
          attended++;
          usedDays.insert(i);
          break;
        }
      }
    }
    
    return attended;
  }
};
