#include <set>
#include <string>
#include <vector>

class Solution { // Sep 15, 2025
public:
  int canBeTypedWords(std::string text, std::string brokenLetters) {
    std::vector<std::string> words;
    std::string word;
    for(char i : text) {
      if(i == ' ') {
        words.push_back(word);
        word.clear();
      } else {
        word += i;
      }
    }
    words.push_back(word);

    const std::set<char> brokenLettersSet(brokenLetters.begin(), brokenLetters.end());
    int res = 0;
    for(std::string word : words) {
      res++;
      for(char i : word) {
        if(brokenLettersSet.find(i) != brokenLettersSet.end()) {
          res--;
          break;
        }
      }
    }

    return res;
  }
};
