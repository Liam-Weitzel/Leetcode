#include <algorithm>
#include <memory>
#include <iostream>
#include <string>

class Solution { // Apr 01, 2024
public:
  int lengthOfLastWord(std::string s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::bind1st(std::not_equal_to<char>(), ' ')).base(), s.end());
    std::size_t lastWordStart = s.find_last_of(' ');
    if(lastWordStart == std::string::npos) lastWordStart = 0;
    else lastWordStart++;
    return s.substr(lastWordStart).size();
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->lengthOfLastWord("   fly me   to   the moon  ") << std::endl;
  return 0;
}
