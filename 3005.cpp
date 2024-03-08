#include <map>
#include <memory>
#include <iostream>
#include <vector>

class Solution { // Mar 08, 2024
public:
  int maxFrequencyElements(std::vector<int>& nums) {
    std::map<int, int> frequencyMap;
    int max = 0;
    for(int i : nums) {
      frequencyMap[i]++;
      if(frequencyMap[i] > max) max = frequencyMap[i];
    }

    int res = 0;
    for(std::pair<int, int> i : frequencyMap) {
      if(i.second == max) res += i.second;
    }

    return res;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> testCase = {1,2,3,3,4,5,6,7,77,78,8,9};
  std::cout << res->maxFrequencyElements(testCase) << std::endl;
  return 0;
}
