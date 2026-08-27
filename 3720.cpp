#include <map>
#include <string>

class Solution { // Aug 27, 2026
public:
  std::string lexGreaterPermutation(std::string s, std::string target) {
    //the next greatest permutation of s that is greater than target (lexicographically)
    //we can't sort... we have to do it manually
    //i guess we make a freq table of s, then iterate over target and always pick the closest match? First come first serve?
    std::map<char, int> freq;
    for(char i : s) { 
      freq[i]++;
    }

    bool deviated = false;
    std::string result = "";
    for(char i : target) {
      for (auto it = freq.lower_bound(i); it != freq.end(); ++it) {
        if (it->second != 0) {
          if(it->first != i) deviated = true;
          result.push_back(it->first);
          it->second--;
          if(deviated) {
            for(auto cur : freq)
              for(int i = 0; i < cur.second; i++)
                result.push_back(cur.first);
            goto last;
          }
        }
      }
    }

    last:
    if(target == result || result.size() != target.size()) return "";
    return result;
  }
};
