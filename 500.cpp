#include <cctype>
#include <string>
#include <unordered_set>
#include <vector>

class Solution { // Nov 25, 2026
public:
  std::vector<std::string> findWords(std::vector<std::string>& words) {
    std::unordered_set<char> first = {'q','w','e','r','t','y','u','i','o','p'};
    std::unordered_set<char> second = {'a','s','d','f','g','h','j','k','l'};
    std::unordered_set<char> third = {'z','x','c','v','b','n','m'};

    std::vector<std::string> res;

    for(std::string word : words) {
      std::unordered_set<char>* row = nullptr;

      char firstChar = std::tolower(word[0]);
      if(first.contains(firstChar)) row = &first;
      else if(second.contains(firstChar)) row = &second;
      else if(third.contains(firstChar)) row = &third;
      else continue;

      bool fit = true;

      for(char c : word) {
        if(!row->contains(std::tolower(c))) {
          fit = false;
          break;
        }
      }

      if(fit) res.push_back(word);
    }

    return res;
  }
};
