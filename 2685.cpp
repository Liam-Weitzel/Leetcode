#include <map>
#include <set>
#include <utility>
#include <vector>

class Solution { // Jul 11, 2026
private:
  std::pair<int, int> dfs(std::map<int, std::vector<int>>& adjMap, int cur, std::set<int>& visited) {
    visited.insert(cur);
    std::pair<int, int> res = std::make_pair(1, 0);
    for(int i : adjMap[cur]) {
      res.second++;
      if(visited.find(i) == visited.end()) {
        std::pair<int, int> ret = dfs(adjMap, i, visited);
        res.first += ret.first;
        res.second += ret.second;
      }
    }
    return res;
  }

public:
  int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
    std::map<int, std::vector<int>> adjMap;
    for(std::vector<int> i : edges) {
      adjMap[i[0]].push_back(i[1]);
      adjMap[i[1]].push_back(i[0]);
    }

    std::set<int> visited;
    int res = 0;
    for(int i = 0; i < n; i++) {
      if(visited.find(i) == visited.end()) {
        std::pair<int, int> ret = dfs(adjMap, i, visited);
        ret.second /= 2;
        if(ret.first*(ret.first-1)/2 == ret.second) res++;
      }
    }

    return res;
  }
};
