#include <iostream>
#include <set>
#include <vector>
#include <string>

class Solution { // Jun 07, 2024
private:
  std::vector<std::string> getWords(std::string s){
    std::vector<std::string> res;
    int pos = s.find(' ');
    while(pos < s.size()){
      res.push_back(s.substr(0,pos));
      s.erase(0,pos+1);
      pos = s.find(' ');
    }
    return res;
  }

public:
  std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
    std::set<std::string> dict(dictionary.begin(), dictionary.end());
    std::vector<std::string> words = getWords(sentence.append(" "));

    for(std::string& word : words) {
      for(int i = 1; i <= word.length()-1; i++) {
        std::string currRoot = word.substr(0, i);
        if(dict.find(currRoot) != dict.end()) {
          word = currRoot;
          break;
        }
      }
    }

    std::string res = "";
    for(std::string& word : words) {
      res.append(word + ' ');
    }
    res = res.substr(0, res.length()-1);

    return res;
  }
};

int main (int argc, char *argv[]) {
  Solution res;
  std::vector<std::string> dictionary = {"cat","bat","rat"};
  std::string sentence = "the cattle was rattled by the battery";
  std::cout << res.replaceWords(dictionary, sentence) << std::endl;
  return 0;
}
