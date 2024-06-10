#include <array>
#include <vector>
#include <iostream>

class Solution { // Jan 10, 2024
public:
  int heightChecker(std::vector<int>& heights) {
    std::array<int, 101> map;
    for(int i : heights) {
      map[i]++;
    }

    std::vector<int> res;
    for(int i = 0; i < map.size(); i++) {
      for(int j = 0; j < map[i]; j++) res.push_back(i);
    }

    int count = 0;
    for(int i = 0; i < heights.size(); i++) {
      if(heights[i] !=  res[i]) count++;
    }

    return count;
  }
};

int main (int argc, char *argv[]) {
  Solution res;
  std::vector<int> heights = {1,1,4,2,1,3};
  std::cout << res.heightChecker(heights) << std::endl;
  return 0;
}
