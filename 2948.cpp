#include <cstdlib>
#include <set>
#include <vector>

class Solution { // Aug 29, 2026
private:
  struct Node {
    int val;
    int index;
    std::vector<Node*> neighbours;
  };

  void dfs(Node* node, std::set<Node*>& visited) {
    if(visited.contains(node)) return;
    visited.insert(node);
    for(Node* i : node->neighbours) dfs(i, visited);
  }

public:
  std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
    //so we can flip but with a limitation
    //limitation being that the absolute diff needs to be above limit in order for the swap to happen
    //so if limit is low, we can only swap elements that are close to each other
    //in order to know which numbers can switch with which we need a std::unordered_map<int, std::vector<int>> thats O^2
    //instead we can also contstruct a graph of nodes that we can swap because if we can switch it with one
    //we can also switch it with the other
    //take this case for example: [1, 2, 3] limit = 1.
    //here we can't switch 1 and 3 but we can actually switch their places by first switching to 2 and then from 2 to 3.
    //so we get multiple disconnected graphs of indices which we can switch.
    //1, 5, 3, 9, 8 - limit = 2
    //1 - 3 - 5
    //9 - 8
    //and now we just need to go through each graph and find the lexicographicallySmallestArray

    //Construct graph
    std::vector<Node*> graph(nums.size());
    for(int i = 0; i < nums.size(); i++) {
      graph[i] = new Node;
      graph[i]->val = nums[i];
      graph[i]->index = i;
    }

    for(int i = 0; i < nums.size(); ++i)
      for(int j = i+1; j < nums.size(); ++j)
        if(std::abs(nums[i] - nums[j]) <= limit) {
          graph[i]->neighbours.push_back(graph[j]);
          graph[j]->neighbours.push_back(graph[i]);
        }

    //Find all disconnected sections using dfs
    std::set<Node*> totalVisited;
    std::vector<std::set<Node*>> groups;
    for(Node* i : graph) {
      if(totalVisited.contains(i)) continue;
      std::set<Node*> visited;
      dfs(i, visited);
      groups.push_back(visited);
      for(Node* j : visited) totalVisited.insert(j);
      //NOTE: this looks O^2 but isnt as it prevents future iterations
    }

    //Construct res & sort each disconnected section lexicographically
    std::vector<int> res(nums.size());

    for(const std::set<Node*>& group : groups) {
      std::vector<int> indices;
      std::vector<int> values;

      for(Node* node : group) {
        indices.push_back(node->index);
        values.push_back(node->val);
      }

      std::sort(indices.begin(), indices.end());
      std::sort(values.begin(), values.end());

      for(int i = 0; i < indices.size(); ++i) {
        res[indices[i]] = values[i];
      }
    }

    //This solution is TLE, as graph construction is O^2 and DFS is O(V+E) potentially O^2 as well.
    //We don't actually need to construct the graph
    //When we sort the numbers by value, a connected component consists of consecutive
    //values where every adjacent gap is <= limit.
    //sort values/index pairs       O(n log n)
    //scan adjacent values          O(n)
    //split whenever gap > limit
    //Then for each group, you already have its values in sorted order.
    //We just need to know which original indices belong to that group, sort those indices, and assign.

    return res;
  }
};
