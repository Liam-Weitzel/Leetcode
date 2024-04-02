#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Solution { // Apr 02, 2024
public:
  bool isIsomorphic(std::string s, std::string t) {
    std::unordered_map<char, int> charOrderSeenS;
    std::vector<int> normalizedStringS;
    int charsSeenS = 0;
    for(char i : s) {
      if(charOrderSeenS[i] != 0) {
        normalizedStringS.push_back(charOrderSeenS[i]);
      } else {
        charsSeenS++;
        charOrderSeenS[i] = charsSeenS;
        normalizedStringS.push_back(charsSeenS);
      }
    }

    std::unordered_map<char, int> charOrderSeenT;
    std::vector<int> normalizedStringT;
    int charsSeenT = 0;
    for(char i : t) {
      if(charOrderSeenT[i] != 0) {
        normalizedStringT.push_back(charOrderSeenT[i]);
      } else {
        charsSeenT++;
        charOrderSeenT[i] = charsSeenT;
        normalizedStringT.push_back(charsSeenT);
      }
    }

    return normalizedStringS == normalizedStringT;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->isIsomorphic("egg", "add") << std::endl;
  return 0;
}
