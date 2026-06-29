#include <string>
#include <vector>

class Solution { // Jun 29, 2026
public:
  int numOfStrings(std::vector<std::string>& patterns, std::string word) {
    int count = 0;
    for(std::string i : patterns) 
      if(word.find(i) != -1)
        count++;

    return count;
  }
};
// WARNING: THERE IS A O(N+P) SOLUTION! NOT O(N*P).
// HINT: TRIE
