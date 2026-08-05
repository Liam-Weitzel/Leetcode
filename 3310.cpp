#include <set>
#include <unordered_map>
#include <vector>

class Solution { // Aug 05, 2026
private:
  bool dfs(int node, std::unordered_map<int, std::vector<int>>& adjMap, std::set<int>& visited, std::set<int>& unvisited, std::set<int>& infected, bool infectedRun) {
    if(visited.contains(node)) return !infectedRun && infected.contains(node);
    if(!infectedRun && infected.contains(node)) return true;
    if(infectedRun) infected.insert(node);
    visited.insert(node);
    unvisited.erase(node);

    bool res = false;
    for(int i : adjMap[node]) res += dfs(i, adjMap, visited, unvisited, infected, infectedRun);

    return res;
  }
public:
  std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
    //we have a directed acyclic graph, one node is 'infected'
    //we want to remove the 'infected' part (indicated by k)
    //we can't remove it there are only edges DIRECTLY DOWNSTREAM of the infected part.
    
    //we start DFS from infected node
    //then we iterate over unvisited nodes & check if they are connected to the infected part.
    //if they are, we return all nodes (remove nothing)
    //if they are not, we remove the infected nodes & return.

    std::unordered_map<int, std::vector<int>> adjMap;
    for(std::vector<int> i : invocations) adjMap[i[0]].push_back(i[1]);
    std::set<int> visited;
    std::set<int> unvisited;
    std::vector<int> res;
    for(int i = 0; i < n; i++) {
      unvisited.insert(i);
      res.push_back(i);
    }
    std::set<int> infected;
    dfs(k, adjMap, visited, unvisited, infected, true);
    bool canNotRemove = false;
    while(visited.size() < n) canNotRemove += dfs(*unvisited.begin(), adjMap, visited, unvisited, infected, false);
    if(canNotRemove) return res;
    std::vector<int> res2;
    for(int i : infected) visited.erase(i);
    for(int i : visited) res2.push_back(i);
    return res2;
    // Suuper rushed solution as im on the train and about to get off, first of all we don't need visited at all.
    // Secondly all the set to vector <-> set conversions are ugly.
    // Needs to be refactored.
  }
};
