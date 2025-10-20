#include <vector>
#include <string>

class Solution { // Oct 20, 2025
public:
  int finalValueAfterOperations(std::vector<std::string>& operations) {
    int res = 0;
    for(std::string i : operations) {
      if(i.find('-') != -1) {
        res--;
      } else {
        res++;
      }
    }
    return 0;
  }
};
