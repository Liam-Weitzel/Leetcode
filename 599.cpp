#include <map>
#include <string>
#include <vector>

class Solution { // Nov 27, 2026
public:
  std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
    std::map<std::string, std::pair<int, int>> duplicates;
    for(int i = 0; i < list1.size(); i++) duplicates[list1[i]].first = i+1;
    for(int i = 0; i < list2.size(); i++) duplicates[list2[i]].second = i+1;

    std::map<int, std::vector<std::string>> indexSum;
    for(std::pair<std::string, std::pair<int, int>> k : duplicates)
      if(k.second.first != 0 && k.second.second != 0)
        indexSum[k.second.first + k.second.second].push_back(k.first);

    return indexSum.begin()->second;
  }
};
