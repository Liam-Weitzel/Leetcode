#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution { // Jul 31, 2026
public:
  int minimumPushes(std::string word) {
    //greedy O(n*Log(N)) approach

    //count char frequencies
    std::unordered_map<char, int> freqMap;
    for(char i : word) freqMap[i]++;

    // std::cout << "freqMap: " << std::endl;
    // for(std::pair<char, int> i : freqMap) std::cout << i.first << " " << i.second << std::endl;

    //sort based on freqeuncy
    std::vector<std::pair<int, char>> sortedByFreq;
    sortedByFreq.reserve(freqMap.size());
    for(std::pair<char, int> i : freqMap) sortedByFreq.push_back(std::make_pair(i.second, i.first));
    std::sort(sortedByFreq.begin(), sortedByFreq.end(), std::greater<std::pair<int,char>>());

    // std::cout << "sortedByFreq: " << std::endl;
    // for(std::pair<int, char> i : sortedByFreq) std::cout << i.first << " " << i.second << std::endl;

    //count key presses, assigning most frequent chars first
    std::unordered_map<char, int> costPerKey;
    int assigned = 0;
    int cur = 0;
    for(std::pair<int, char> i : sortedByFreq) {
      costPerKey[i.second] = (cur/8)+1;
      cur++;
    }

    // std::cout << "costPerKey: " << std::endl;
    // for(std::pair<char, int> i : costPerKey) std::cout << i.first << " " << i.second << std::endl;

    //count total cost
    int res = 0;
    for(char i : word) res += costPerKey[i];

    return res;
  }
};
