#include <string>
#include <vector>

class Solution { // Oct 27, 2025
public:
  int numberOfBeams(std::vector<std::string>& bank) {
    int res = 0;
    int prev = 0;
    for(std::string i : bank) {
      int count = 0;
      for(char c : i) {
        if(c == '1') count++;
      }

      if(count > 0) {
        res += prev * count;
        prev = count;
      }
    }
    return res;
  }
};
