#include <iostream>
#include <map>
#include <utility>
#include <vector>

class Solution { // Jun 27, 2024
public:
  int findCenter(std::vector<std::vector<int>>& edges) {
    std::map<int, std::vector<int>> adjacencyMap;
    for(std::vector<int> i : edges) {
      adjacencyMap[i[0]].push_back(i[1]);
      adjacencyMap[i[1]].push_back(i[0]);
    }

    int centerConnections = adjacencyMap.size()-1;
    int res = -1;
    for(std::pair<int, std::vector<int>> i : adjacencyMap) {
      if(i.second.size() == centerConnections) {
        res = i.first;
        break;
      }
    }

    return res;
  }
};

void testSolution(std::vector<std::vector<int>> edges, int expected) {
  Solution res;
  int ans = res.findCenter(edges);

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
  testSolution({{1,2},{2,3},{4,2}}, 2);
  testSolution({{1,2},{5,1},{1,3},{1,4}}, 1);
}
