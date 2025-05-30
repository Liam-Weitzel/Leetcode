#include <climits>
#include <iostream>
#include <vector>

class Solution { // May 30, 2025
private:
  void dfsStepsToNode(std::vector<int>& res, std::vector<int>& edges, int node, int steps, std::vector<bool>& visited) {
    if (node < 0 || node >= visited.size()) return;
    visited[node] = true;
    if(steps < res[node]) res[node] = steps;
    int next = edges[node];
    if(next >= 0 && next < visited.size() && !visited[next]) {
      dfsStepsToNode(res, edges, next, steps+1, visited);
    }
  }

public:
  int closestMeetingNode(std::vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    int MAX = 10000000;

    std::vector<int> node1Steps(n, MAX);
    std::vector<bool> visited1(n, false);
    dfsStepsToNode(node1Steps, edges, node1, 0, visited1);

    std::vector<int> node2Steps(n, MAX);
    std::vector<bool> visited2(n, false);
    dfsStepsToNode(node2Steps, edges, node2, 0, visited2);

    std::vector<int> sumSteps(n);
    for(int i = 0; i < n; i++) sumSteps[i] = node1Steps[i] + node2Steps[i];

    int minDist = MAX;
    int result = -1;

    for(int i = 0; i < n; i++) {
      if(node1Steps[i] == MAX || node2Steps[i] == MAX) continue;
      int maxDist = std::max(node1Steps[i], node2Steps[i]);
      if(maxDist < minDist) {
        minDist = maxDist;
        result = i;
      }
    }

    return result;
  }
};

void testSolution(std::vector<int> edges, int node1, int node2, int expected) {
  Solution res;
  int ans = res.closestMeetingNode(edges, node1, node2);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "edges: ";
  for(int i : edges) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Node1: " << node1 << std::endl;

  std::cout << "Node2: " << node2 << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({2,2,3,-1}, 0, 1, 2);
  testSolution({1,2,-1}, 0, 2, 2);
  testSolution({4,3,0,5,3,-1}, 4, 0, 4);
}
