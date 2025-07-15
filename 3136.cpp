#include <set>
#include <string>

class Solution { // Jul 15, 2025
public:
  bool isValid(std::string word) {
    bool vowelPresent = false;
    bool consonantPresent = false;
    std::set<char> forbidden = {'@', '#', '$'};
    std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    std::set<char> consonant = {'Q', 'W', 'F', 'P', 'B', 'M', 'L', 'Y', 'J', 'R', 'S', 'T', 'G', 'N', 'Z', 'X', 'C', 'D', 'V', 'K', 'H', 'q', 'w', 'f', 'p', 'b', 'm', 'l', 'y', 'j', 'r', 's', 't', 'g', 'n', 'z', 'x', 'c', 'd', 'v', 'k', 'h'};

    for(char i : word) {
      if(forbidden.contains(i)) return false;
      else if(vowels.contains(i)) vowelPresent = true;
      else if(consonant.contains(i)) consonantPresent = true;
    }

    return word.size() >= 3 && vowelPresent && consonantPresent;
  }
};
