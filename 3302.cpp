#include <string>
#include <vector>

class Solution { // Aug 08, 2026
public:
  std::vector<int> validSequence(std::string word1, std::string word2) {
    int n = word1.size(), m = word2.size();
    std::vector<int> minJ(n + 1);
    minJ[n] = m;
    for (int i = n - 1; i >= 0; i--) {
      minJ[i] = minJ[i + 1];
      if (minJ[i] > 0 && word1[i] == word2[minJ[i] - 1]) {
        minJ[i]--;
      }
    }
    
    int i = 0, j = 0;
    bool swapUsed = false;
    std::vector<int> res;

    while (i < n && j < m) {
      if (word1[i] == word2[j]) {
        res.push_back(i);
        i++; j++;
      } else if (!swapUsed && minJ[i + 1] <= j + 1) {
        res.push_back(i);
        i++; j++;
        swapUsed = true;
      } else {
        i++;
      }
    }

    if (j == (int)m) return res;
    return {};
  }
};
