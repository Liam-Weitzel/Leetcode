#include <string>
#include <vector>

class Solution { // Nov 27, 2026
public:
  std::string reverseWords(std::string s) {
    std::vector<std::string> words;

    int start = 0;
    int size = 0;
    for(char i : s) {
      size++;
      if(i == ' ') {
        words.push_back(s.substr(start, size-1));
        start+=size;
        size=0;
      }
    }
    words.push_back(s.substr(start, size));

    std::string res = "";

    for(std::string word : words) {
      std::string temp = "";
      for(int i = word.length()-1; i >= 0; i--)
        temp += word[i];
      res += temp;
      res += " ";
    }

    res.erase(res.length()-1,1);

    return res;
  }
};
