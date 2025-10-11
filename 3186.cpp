#include <map>
#include <set>
#include <utility>
#include <vector>

class Solution { // Oct 11, 2025
private:
  void dfs(std::map<std::pair<int, bool>, std::pair<long long, std::vector<int>>>& memo, int curIndex, std::vector<int>& power, bool take) {
    if(curIndex == power.size()) return;
    std::pair<int, bool> cur = std::make_pair(curIndex, take);
    if(memo.find(cur) != memo.end()) return;

    long long max = take ? power[curIndex] : 0;
    std::set<int> cantTake = {power[curIndex]-2, power[curIndex]-1, power[curIndex]+1, power[curIndex]+2};
    dfs(memo, curIndex+1, power, true);
    std::pair<long long, std::vector<int>> left = memo[std::make_pair(curIndex+1, true)];
    std::vector<int> canTake = {};
    dfs(memo, curIndex+1, power, false);
    std::pair<long long, std::vector<int>> right = memo[std::make_pair(curIndex+1, false)];

    return;
  }

public:
  long long maximumTotalDamage(std::vector<int>& power) {
    std::map<std::pair<int, bool>, std::pair<long long, std::vector<int>>> memo;
    //key = (index, take or no take?), value = (maxPower, taken)
    dfs(memo, 0, power, false);
    dfs(memo, 0, power, true);
    return std::max(memo[std::make_pair(0, false)].first, memo[std::make_pair(0, true)].first);
  }
};
