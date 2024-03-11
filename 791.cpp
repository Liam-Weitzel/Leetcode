#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution { // Mar 11, 2024
public:
  std::string customSortString(std::string order, std::string s) {
    std::unordered_set<char> orderSet(order.begin(), order.end());
    std::unordered_map<char, int> sOverlapCount;
    std::string res;

    for(char i : s) {
      if(orderSet.find(i) != orderSet.end()) sOverlapCount[i]++;
      else res.push_back(i);
    }

    for(char i : order) res.insert(res.end(), sOverlapCount[i], i);

    return res;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->customSortString("cba", "abcd") << std::endl;
  return 0;
}
