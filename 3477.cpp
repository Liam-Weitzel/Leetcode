#include <vector>

class Solution { // Aug 05, 2025
public:
  int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {

    int unplaced = 0;
    for(int i : fruits) {
      bool found = false;
      for(int j = 0; j < baskets.size(); j++) {
        if(baskets[j] >= i) {
          found = true;
          baskets[j] = -1;
          break;
        }
      }
      if(!found) unplaced++;
    }

    return unplaced;
  }
};
