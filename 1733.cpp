#include <algorithm>
#include <map>
#include <set>
#include <vector>

class Solution { // Sep 10, 2025
private:
struct NodeInfo {
    std::set<int> friends;
    std::set<int> languages;
    bool canCommunicateWithAll = false;
};

public:
  int minimumTeachings(int n, std::vector<std::vector<int>>& languages, std::vector<std::vector<int>>& friendships) {
    std::map<int, NodeInfo> nodeMap;

    for(std::vector<int> i : friendships) {
      nodeMap[i[0]].friends.insert(i[1]);
      nodeMap[i[1]].friends.insert(i[0]);
    }

    for(int i = 0; i < languages.size(); i++) {
      std::vector<int> v = languages[i];
      std::set<int> s(v.begin(), v.end());
      nodeMap[i+1].languages = s;
    }

    for(std::pair<int, NodeInfo> i : nodeMap) {
      nodeMap[i.first].canCommunicateWithAll = true;
      for(int j : i.second.friends) {
        std::vector<int> intersection;
        std::set_intersection(nodeMap[j].languages.begin(), nodeMap[j].languages.end(),
          i.second.languages.begin(), i.second.languages.end(),
          std::back_inserter(intersection));
        if(intersection.empty()) {
          nodeMap[i.first].canCommunicateWithAll = false;
          break;
        }
      }
    }

    std::vector<int> langCount(n, 0);
    for(std::pair<int, NodeInfo> i : nodeMap) {
      if(!i.second.canCommunicateWithAll) {
        for(int j : i.second.languages) {
          langCount[j-1]++;
        }
      }
    }

    int languageToBeTaught = *std::max_element(langCount.begin(), langCount.end());

    int teachCount = 0;
    for(std::pair<int, NodeInfo> i : nodeMap) {
      if(!i.second.canCommunicateWithAll) {
        if(!i.second.languages.contains(languageToBeTaught)) {
          teachCount++;
        }
      }
    }

    return teachCount;
  }
};
