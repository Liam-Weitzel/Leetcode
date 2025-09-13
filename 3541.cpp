#include <algorithm>
#include <map>
#include <set>
#include <string>

bool comp(std::pair<char, int> a, std::pair<char, int> b) {
  if(a.second > b.second) return false;
  return true;
}

class Solution { // Sep 13, 2025
public:
  int maxFreqSum(std::string s) {
    std::map<char, int> vowelFreqMap;
    std::map<char, int> consFreqMap;
    std::set<char> vowels = {'a','e','i','o','u'};

    for(char i : s) {
      if(vowels.find(i) != vowels.end()) {
        vowelFreqMap[i]++;
      } else {
        consFreqMap[i]++;
      }
    }

    std::pair<char, int> vowelMax = *std::max_element(vowelFreqMap.begin(), vowelFreqMap.end(), comp);
    std::pair<char, int> consMax = *std::max_element(consFreqMap.begin(), consFreqMap.end(), comp);

    return vowelMax.second + consMax.second;
  }
};
