#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class Solution { // Sep 14, 2025
private:
  const std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  std::string remove_vowels(std::string s) {
    for(int i = 0; i < s.size(); i++) {
      if(vowels.find(s[i]) != vowels.end()) s[i] = '-';
    }
    return s;
  }

  std::string to_lower(std::string s) {
    for(int i = 0; i < s.size(); i++) {
      s[i] = std::tolower(s[i]);
    }
    return s;
  }

public:
  std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
    std::vector<std::string> res;

    std::set<std::string> wordlistSensitiveSet(wordlist.begin(), wordlist.end());

    std::unordered_map<std::string, std::vector<std::string>> wordlistInsensitiveMap;
    for(std::string i : wordlist) wordlistInsensitiveMap[to_lower(i)].push_back(i);

    std::unordered_map<std::string, std::vector<std::string>> wordlistMap;
    for(std::string i : wordlist) {
      std::string j = remove_vowels(i);
      wordlistMap[to_lower(j)].push_back(i);
    }

    for(std::string i : queries) {
      //first check if we have an exact match
      if(wordlistSensitiveSet.find(i) != wordlistSensitiveSet.end()) {
        res.push_back(i);
        continue;
      }

      //then check if we have a case insensitive match
      if(wordlistInsensitiveMap.find(to_lower(i)) != wordlistInsensitiveMap.end()) {
        res.push_back(wordlistInsensitiveMap[to_lower(i)][0]);
        continue;
      }

      //then check if we have a one vowel missing case insensitive match
      bool added = false;
      std::string removed = remove_vowels(i);
      for(std::string j : wordlistMap[to_lower(removed)]) {
        int strikes = 0;
        for(int c = 0; c < i.size(); c++) {
          if(std::tolower(j[c]) != std::tolower(i[c]) && vowels.find(j[c]) == vowels.end()) {
            strikes++;
            if(strikes == 2) {
              break;
            }
          }
        }
        if(strikes <= 1) {
          res.push_back(j);
          added = true;
          break;
        }
      }
      if(added) continue;

      //else empty string
      res.push_back("");
    }

    return res;
  }
};
