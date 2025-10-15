#include <map>
#include <vector>

class Solution { // Oct 07, 2025
public:
  std::vector<int> avoidFlood(std::vector<int>& rains) {
    //always dry lake on demand -- make a set of currently full lakes as you can't dry if theres no full lake
    //simulate to check what the output will be

    std::map<int, bool> lakes; //true means full
    std::vector<std::map<int, bool>> dry;
    for(int i = 0; i < rains.size(); i++) {
      int rain = rains[i];
      if(rain == 0) {
        dry.push_back(lakes);
      } else {
        if(lakes[rain]) {
          if(dry.size() > 0) {
            for(int j = 0; j < dry.size(); j++) {
              if(dry[j].find(rain) != dry[j].end() && dry[j][rain]) {
                //we could have dried it back then, so we remove this entry from dry and set lakes[rain] to full again.
                dry.erase(std::next(dry.begin(), j));
                break;
              }
            }
          } else {
              return {};
         }
        } else {
          lakes[rain] = true;
        }
      }
    }

    std::vector<int> res;
    res.reserve(lakes.size());
    for(std::pair<int, bool> i : lakes) {
      if(i.second) {
        for(int j = 0; j < dry.size(); j++) {
          if(dry[j].find(i.first) != dry[j].end() && dry[j][i.first]) {
            dry.erase(std::next(dry.begin(), j));
            break;
          }
        }
      } else {
        res.push_back(0);
      }
    }

    // very broken solution (took 40 min)....

    return rains;
  }
};
