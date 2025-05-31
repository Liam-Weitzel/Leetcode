#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Solution { // May 29, 2025
private:
  int bfs(std::vector<std::vector<int>>& tree, int node, bool even, std::vector<int>& counts) {
    if (counts[node] != 0) return counts[node];

    std::queue<std::pair<int, int>> q;
    std::vector<bool> visited(tree.size(), false);

    q.push(std::make_pair(node, 0));
    visited[node] = true;
    int count = 0;

    while(!q.empty()) {
      auto [curr, steps] = q.front();
      q.pop();

      for(int i : tree[curr]) {
        if(!visited[i]) {
          q.push(std::make_pair(i, steps+1));
          visited[i] = true;
          if(even && steps % 2 == 0) count++;
          else if (!even && steps % 2 != 0) count++;
        }
      }
    }
    counts[node] = count;
    return count;
  }

public:
  std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    std::vector<std::vector<int>> tree1(n);
    for(auto& e : edges1) {
      tree1[e[0]].push_back(e[1]);
      tree1[e[1]].push_back(e[0]);
    }

    std::vector<std::vector<int>> tree2(m);
    for(auto& e : edges2) {
      tree2[e[0]].push_back(e[1]);
      tree2[e[1]].push_back(e[0]);
    }

    // NOTE: If BFS for node 0 is lets say 7.. then the neighbours will be n-7... final optimization, hard to implement
    std::vector<int> tree1even(n);
    for(int i = 0; i < n; i++) {
      tree1even[i] = bfs(tree1, i, false, tree1even);
    }

    std::vector<int> tree2odd(m);
    for(int i = 0; i < m; i++) {
      tree2odd[i] = bfs(tree2, i, true, tree2odd);
    }

    std::vector<int> res(n);
    int maxTree2odd = *std::max_element(tree2odd.begin(), tree2odd.end());
    for(int i = 0; i < n; i++) {
      res[i] = tree1even[i] + maxTree2odd + 1;
    }

    return res;
  }
};

void testSolution(std::vector<std::vector<int>> edges1, std::vector<std::vector<int>> edges2, std::vector<int> expected) {
  Solution res;
  std::vector<int> ans = res.maxTargetNodes(edges1, edges2);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Edges1: ";
  for(std::vector<int> i : edges1) std::cout << " [ " << i[0] << ", " << i[1] << " ], ";
  std::cout << std::endl;

  std::cout << "Edges2: ";
  for(std::vector<int> i : edges2) std::cout << " [ " << i[0] << ", " << i[1] << " ], ";
  std::cout << std::endl;

  std::cout << "Ans: ";
  for(int i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;

}

int main (int argc, char *argv[]) {
  testSolution({{0,1},{0,2},{2,3},{2,4}}, {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}}, {8,7,7,8,8});
  testSolution({{0,1},{0,2},{0,3},{0,4}}, {{0,1},{1,2},{2,3}}, {3,6,6,6,6});
}
