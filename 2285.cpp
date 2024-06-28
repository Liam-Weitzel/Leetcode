#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

class Solution { // Jun 28, 2024
public:
  long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
    std::map<int, std::vector<int>> adjacencyMap;
    for(std::vector<int> i : roads) {
      adjacencyMap[i[0]].push_back(i[1]);
      adjacencyMap[i[1]].push_back(i[0]);
    }

    std::vector<std::pair<int, int>> connections;
    for(std::pair<int, std::vector<int>> i : adjacencyMap) {
      connections.push_back(std::make_pair(i.second.size(), i.first));
    }
    
    std::sort(connections.begin(), connections.end(), std::greater());

    std::vector<int> importances(n, 0);
    for(std::pair<int, int> i : connections) {
      importances[i.second] = n;
      n--;
    }

    long long res = 0;
    for(std::vector<int> i : roads) {
      res += (importances[i[0]] + importances[i[1]]);
    }

    return res;
  }
};

void testSolution(int n, std::vector<std::vector<int>> edges, int expected) {
  Solution res;
  int ans = res.maximumImportance(n, edges);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Input: " << std::endl;
  for(std::vector<int> i : edges) std::cout << i[0] << ", " << i[1] << std::endl;;
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl << std::endl;
  std::cout << "Expected: " << expected << std::endl << std::endl;
  std::cout << "-------------------------" << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(5, {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}}, 43);
  testSolution(5, {{0,3},{2,4},{1,3}}, 20);
  testSolution(5, {{0,1}}, 9);
}
