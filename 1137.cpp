#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

class Solution { // Apr 24, 2024
public:
  int tribonacci(int n) {
    if(n == 0) return 0;
    std::vector<int> last = {0,1,1};

    for(int i = 3; i <= n; ++i) {
      int curr = std::accumulate(last.begin(), last.end(), 0);
      last[0] = last[1];
      last[1] = last[2];
      last[2] = curr;
    }

    return last[2];
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->tribonacci(24) << std::endl;
  return 0;
}
