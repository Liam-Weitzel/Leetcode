#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

class Solution { // May 26, 2025
private:
  bool dfs(std::vector<std::vector<int>>& colorCount, 
          const std::string& colors,
          std::vector<std::vector<int>>& adj,
          std::vector<int>& visited,
          int curr) {

    if (visited[curr] == 1) return true;  // cycle detected
    if (visited[curr] == 2) return false; // already processed

    visited[curr] = 1; // mark as being processed

    std::vector<int> currCount(26, 0);
    currCount[colors[curr] - 'a']++;

    for (int next : adj[curr]) {
      if (dfs(colorCount, colors, adj, visited, next)) return true;

      // Update maximum frequencies from child path
      for (int i = 0; i < 26; i++) {
        currCount[i] = std::max(currCount[i], 
                              colorCount[next][i] + (colors[curr] - 'a' == i ? 1 : 0));
      }
    }

    colorCount[curr] = currCount;
    visited[curr] = 2; // mark as processed
    return false;
  }

public:
  int largestPathValue(std::string colors, std::vector<std::vector<int>>& edges) {
    int n = colors.size();

    // Convert edge list to adjacency list for easier traversal
    std::vector<std::vector<int>> adj(n);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    // colorCount[i][j] represents the maximum frequency of color j in any path starting from node i
    std::vector<std::vector<int>> colorCount(n, std::vector<int>(26, 0));

    // visited array to detect cycles: 
    // 0 = unvisited, 1 = in current DFS path (detecting cycles), 2 = fully explored
    std::vector<int> visited(n, 0);

    // Run DFS from each unvisited node to handle disconnected components
    for (int i = 0; i < n; i++) {
      if (visited[i] == 0 && dfs(colorCount, colors, adj, visited, i)) {
        return -1;  // cycle detected
      }
    }

    // Find the maximum color frequency across all paths
    int maxColorValue = 0;
    for (const auto& counts : colorCount) {
      maxColorValue = std::max(maxColorValue, *std::max_element(counts.begin(), counts.end()));
    }

    return maxColorValue;
  }
};


class Solution1 { // May 26, 2025 - Memory limit exceeded
private:
  bool dfs(std::unordered_map<int, std::vector<std::vector<int>>>& memo, 
           const std::string& colors,
           std::vector<std::vector<int>>& adj,
           int curr, 
           std::set<int>& visited) {

    if (visited.count(curr)) return true; // True indicates a cycle
    if (memo.count(curr)) return false;

    visited.insert(curr);

    std::vector<int> freq(26, 0);
    freq[colors[curr] - 'a'] = 1;

    // Store all possible paths from current node
    std::vector<std::vector<int>> paths;
    paths.push_back(freq); // Add initial path with just current node

    // Process all neighbors
    for (int next : adj[curr]) {
      if (dfs(memo, colors, adj, next, visited)) return true; // Propagate the cycle detection

      for (const std::vector<int>& childPath : memo[next]) {
        std::vector<int> newPath = childPath;
        newPath[colors[curr] - 'a']++;
        paths.push_back(newPath);
      }
    }

    memo[curr] = paths;
    visited.erase(curr);

    // No cycle detected
    return false;
  }

public:
  int largestPathValue(std::string colors, std::vector<std::vector<int>>& edges) {
    int numNodes = colors.size();

    // Create adjacency list
    std::vector<std::vector<int>> adj(numNodes);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    // Find root nodes
    std::vector<bool> isRoot(numNodes, true);
    for (const auto& edge : edges) {
      isRoot[edge[1]] = false;
    }

    std::vector<int> rootNodes;
    for (int i = 0; i < numNodes; i++) {
      if (isRoot[i]) rootNodes.push_back(i);
    }

    // If no root nodes found and graph is not empty, must have a cycle
    if (rootNodes.empty() && !edges.empty()) return -1;

    std::unordered_map<int, std::vector<std::vector<int>>> memo;
    std::set<int> visited;

    // Run DFS from each root node
    for (int root : rootNodes) {
      if (dfs(memo, colors, adj, root, visited)) return -1;
    }

    // Find maximum color value
    int maxColorValue = 0;
    for (const auto& [node, paths] : memo) {
      for (const auto& path : paths) {
        maxColorValue = std::max(maxColorValue, *std::max_element(path.begin(), path.end()));
      }
    }
    
    return maxColorValue;
  }
};

void testSolution(std::string colors, std::vector<std::vector<int>> edges, int expected) {
  Solution res;
  int ans = res.largestPathValue(colors, edges);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Colors: " << colors << std::endl;

  std::cout << "Edges: ";
  for(std::vector<int> i : edges) std::cout << " [ " << i[0] << ", " << i[1] << " ], ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("abaca", {{0,1},{0,2},{2,3},{3,4}}, 3);
  testSolution("a", {{0,0}}, -1);
  testSolution("hwuyyyyuyhwwhuhwwwwhuyhuuhwwyuwyuhwhuwuyhuhhuyuuwuhw", {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{3,6},{6,7},{7,8},{4,8},{8,9},{7,9},{7,10},{10,11},{8,12},{8,13},{11,13},{12,14},{13,14},{10,14},{8,15},{15,16},{12,16},{11,16},{16,17},{9,17},{13,17},{15,18},{17,18},{9,19},{13,19},{18,20},{19,20},{16,20},{15,21},{20,21},{17,21},{18,21},{18,22},{21,22},{21,23},{22,23},{21,24},{24,25},{20,25},{12,25},{14,26},{25,27},{25,28},{26,28},{28,29},{27,29},{23,29},{27,30},{29,30},{10,30},{28,31},{29,31},{27,31},{30,31},{23,32},{31,32},{20,33},{27,33},{33,34},{30,34},{32,34},{28,34},{31,35},{4,35},{25,35},{34,35},{31,36},{30,36},{34,36},{35,36},{26,36},{33,37},{37,38},{36,38},{34,38},{33,39},{36,39},{38,39},{38,40},{39,40},{37,40},{33,40},{36,40},{40,41},{39,41},{35,41},{25,41},{23,42},{27,42},{39,42},{18,43},{35,43},{42,44},{33,45},{34,46},{43,46},{45,46},{44,47},{46,47},{37,48},{40,48},{36,49},{47,49},{37,49},{46,49},{48,49},{48,50},{49,50},{48,51}}, 12);
}
