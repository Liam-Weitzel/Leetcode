#include <cstdlib>
#include <string>
#include <vector>

class Solution { // Sep 23, 2025
public:
  int compareVersion(std::string version1, std::string version2) {
    std::vector<int> version1vec;
    std::string curr = "";
    for(char i : version1) {
      if(i == '.') {
        version1vec.push_back(atoi(curr.c_str()));
        curr = "";
      } else {
        curr += i;
      }
    }
    version1vec.push_back(atoi(curr.c_str()));
    curr = "";

    std::vector<int> version2vec;
    curr = "";
    for(char i : version2) {
      if(i == '.') {
        version2vec.push_back(atoi(curr.c_str()));
        curr = "";
      } else {
        curr += i;
      }
    }
    version2vec.push_back(atoi(curr.c_str()));
    curr = "";

    int diff = version1vec.size() - version2vec.size();
    if(diff > 0) {
      for(int i = 0; i < diff; i++) {
        version2vec.push_back(0);
      }
    } else if (diff < 0) {
      for(int i = 0; i < abs(diff); i++) {
        version1vec.push_back(0);
      }
    }

    for(int i = 0; i < version1vec.size(); i++) {
      if(version1vec[i] > version2vec[i]) return 1;
      if(version1vec[i] < version2vec[i]) return -1;
    }
    return 0;
  }
};
