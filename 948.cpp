#include <algorithm>
#include <memory>
#include <iostream>
#include <vector>

class Solution { // Mar 04, 2024
public:
  int bagOfTokensScore(std::vector<int>& tokens, int power) {
    std::sort(tokens.begin(), tokens.end(), std::less());
    int score = 0;
    int maxScore = 0;

    while(!tokens.empty()) {
      if(power >= tokens.front()) {
        score++;
        power -= tokens.front();
        tokens.erase(tokens.begin());
      } else if (score >= 1) {
        score -= 1;
        power += tokens.back();
        tokens.pop_back();
      } else {
        tokens.clear();
      }
      maxScore = std::max(score, maxScore);
    }

    return maxScore;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> tokens = {100, 200, 500, 400, 300};
  int power = 200;
  std::cout << res->bagOfTokensScore(tokens, power) << std::endl;
  return 0;
}
