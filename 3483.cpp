#include <set>
#include <vector>

class Solution { // Sep 11, 2026
public:
  int totalNumbers(std::vector<int>& digits) {
    int count = 0;
    std::set<std::vector<int>> seen;
    for(int first = 0; first < digits.size(); first++) {
      if(digits[first] == 0) continue;
      for(int second = 0; second < digits.size(); second++) {
        if(first == second) continue;
        for(int third = 0; third < digits.size(); third++) {
          if(second == third) continue;
          if(first == third) continue;
          if(seen.contains({digits[first], digits[second], digits[third]})) continue;
          if(digits[third]%2==0) {
            count++;
            seen.insert({digits[first], digits[second], digits[third]});
          }
        }
      }
    }
    return count;
  }
};
