#include <iostream>
#include <map>
#include <set>
#include <vector>

class Solution { // Jun 29, 2024
private:
  std::set<int> dfs(int curr, std::map<int, std::vector<int>>& adjacencyMap, std::vector<std::set<int>>& reachableMap) {
    if(reachableMap[curr].size() != 0) return reachableMap[curr];
    std::set<int> visited;
    visited.insert(curr);

    for(int i : adjacencyMap[curr]) {
      std::set<int> res = dfs(i, adjacencyMap, reachableMap);
      visited.insert(res.begin(), res.end());
    }

    reachableMap[curr] = visited;
    return visited;
  }

public:
  std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges) {
    std::map<int, std::vector<int>> adjacencyMap;
    for(std::vector<int> i : edges) {
      adjacencyMap[i[1]].push_back(i[0]);
    }

    std::vector<std::set<int>> reachableMap(n, std::set<int>());
    for(int i = 0; i < n; i++) {
      if(reachableMap[i].size() == 0) {
        dfs(i, adjacencyMap, reachableMap);
      }
    }

    std::vector<std::vector<int>> res(n, std::vector<int>());
    for(int i = 0; i < n; i++) {
      for(int j : reachableMap[i]) if(j != i) res[i].push_back(j);
    }

    return res;
  }
};

void testSolution(int n, std::vector<std::vector<int>> edges, std::vector<std::vector<int>> expected) {
  Solution res;
  std::vector<std::vector<int>> ans = res.getAncestors(n, edges);

  if(ans == expected) std::cout << "\033[1;32m" << std::endl; //Color output green
  else std::cout << "\033[1;31m" << std::endl; //Color output red

  std::cout << "Input: " << std::endl;
  for(std::vector<int> i : edges) std::cout << i[0] << ", " << i[1] << std::endl;
  std::cout << std::endl;

  std::cout << "Output: " << std::endl;
  for(std::vector<int> i : ans) {
    std::cout << "[ ";
    for(int j : i) std::cout << j << " ";
    std::cout << "]" << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Expected: " << std::endl;
  for(std::vector<int> i : expected) {
    std::cout << "[ ";
    for(int j : i) std::cout << j << " ";
    std::cout << "]" << std::endl;
  }
  std::cout << std::endl;

  std::cout << "-------------------------" << "\033[0m" << std::endl;

}

int main (int argc, char *argv[]) {
  testSolution(8, {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}}, {{},{},{},{0,1},{0,2},{0,1,3},{0,1,2,3,4},{0,1,2,3}});
  testSolution(5, {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}, {{},{0},{0,1},{0,1,2},{0,1,2,3}});
}
