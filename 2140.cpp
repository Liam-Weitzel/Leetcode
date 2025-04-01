#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

class Solution { // Apr 01, 2025
public:
  long long mostPoints(std::vector<std::vector<int>>& questions) {
    std::vector<long long> maxPoints(questions.size());
    long long prevMax = LONG_LONG_MIN;
    for(int i = questions.size()-1; i >= 0; i--) {
      if(questions[i][1] + i + 1 >= questions.size()) {
        maxPoints[i] = questions[i][0];
        if(maxPoints[i] < prevMax) maxPoints[i] = prevMax;
      }
      else {
        maxPoints[i] = questions[i][0] + maxPoints[i+questions[i][1]+1];
        if(maxPoints[i] < prevMax) maxPoints[i] = prevMax;
      }
      prevMax = maxPoints[i];
    }
    return *std::max_element(maxPoints.begin(), maxPoints.end());
  }
};

void testSolution(std::vector<std::vector<int>> questions, long long expected) {
  Solution res;
  long long ans = res.mostPoints(questions);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Questions: ";
  for(std::vector<int> i : questions) std::cout << "[" << i[0] << ", " << i[1] << "] ";
  std::cout << std::endl;

  std::cout << "Answer: \"" << ans << "\"" << std::endl;

  std::cout << "Expected: \"" << expected << "\"" << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({{3, 2}, {4, 3}, {4, 4}, {2, 5}}, 5);
  testSolution({{1,1},{2,2},{3,3},{4,4},{5,5}}, 7);
  testSolution({{21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3}}, 157);
}
