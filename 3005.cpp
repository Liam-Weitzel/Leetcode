#include <algorithm>
#include <map>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution { // Sep 22, 2025
public:
  int maxFrequencyElements(std::vector<int>& nums) {
    std::unordered_map<int, int> freqMap;
    for(int i : nums) freqMap[i]++;
    int max = std::max_element(
      freqMap.begin(), freqMap.end(),
      [](const auto &a, const auto &b) {
        return a.second < b.second;
      }
    )->second;
    int res = 0;
    for(std::pair<int, int> i : freqMap) {
      if(i.second == max) res += max;
    }
    return res;
  }
};

class Solution2 { // Mar 08, 2024
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
