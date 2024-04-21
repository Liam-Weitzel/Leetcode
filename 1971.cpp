#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

class Solution { // Apr 21, 2024
private:
  bool dfs(std::unordered_map<int, std::vector<int>>& adjacencyMap, int curr, int dest, std::set<int>& visited) {
    if(curr == dest) return true;
    bool res = false;
    visited.insert(curr);
    for(int next : adjacencyMap[curr]) {
      if(visited.find(next) == visited.end()) res = std::max(dfs(adjacencyMap, next, dest, visited), res);
      if(res) break;
    }
    return res;
  }
public:
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    std::unordered_map<int, std::vector<int>> adjacencyMap;
    for(std::vector<int> edge : edges) {
      adjacencyMap[edge[0]].push_back(edge[1]);
      adjacencyMap[edge[1]].push_back(edge[0]);
    }
    std::set<int> visited;
    return dfs(adjacencyMap, source, destination, visited);
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  int n = 3;
  std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,0}};
  int source = 0;
  int destination = 2;
  std::cout << res->validPath(n, edges, source, destination) << std::endl;
  return 0;
}
