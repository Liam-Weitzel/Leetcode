#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

class Solution { // Mar 13, 2024
public:
  int pivotInteger(int n) {
    std::vector<int> range(n);
    std::iota(range.begin(), range.end(), 1);
    int prefixSum = 0;
    int suffixSum = std::accumulate(range.begin(), range.end(), 0);

    for ( int i : range ) {
      prefixSum += i;
      if(prefixSum == suffixSum) return i;
      suffixSum -= i;
    }

    return -1;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->pivotInteger(8) << std::endl;
  return 0;
}
