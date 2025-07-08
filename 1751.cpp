#include <map>
#include <vector>

class Solution { // Jul 08, 2025
private:
  std::map<std::pair<int, int>, int> memo;
  int maxDay;

  //find the max value starting at a given day
  int dfs(int day, int k, std::map<int, std::vector<std::pair<int, int>>>& eventsMap) {
    if (k == 0 || day > maxDay) return 0;

    auto memoKey = std::make_pair(day, k);
    if (memo.contains(memoKey)) return memo[memoKey];

    int maxVal = 0;

    //skip today, move to next available day with events
    auto nextDayIt = eventsMap.upper_bound(day);
    if (nextDayIt != eventsMap.end()) {
      maxVal = dfs(nextDayIt->first, k, eventsMap);
    }

    //take any event that starts today
    auto it = eventsMap.find(day);
    if (it != eventsMap.end()) {
      for (const auto& [endDay, value] : it->second) {
        //after taking this event, move to next available day after endDay
        auto nextIt = eventsMap.upper_bound(endDay);
        int nextDay = (nextIt != eventsMap.end()) ? nextIt->first : maxDay + 1;
        maxVal = std::max(maxVal, value + dfs(nextDay, k - 1, eventsMap));
      }
    }

    return memo[memoKey] = maxVal;
  }

public:
  int maxValue(std::vector<std::vector<int>>& events, int k) {
    std::map<int, std::vector<std::pair<int, int>>> eventsMap;
    maxDay = 0;

    for (const auto& e : events) {
      eventsMap[e[0]].emplace_back(e[1], e[2]);
      maxDay = std::max(maxDay, e[1]);
    }

    return dfs(eventsMap.begin()->first, k, eventsMap);
  }
};
