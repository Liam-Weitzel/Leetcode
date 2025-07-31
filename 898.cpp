#include <set>
#include <unordered_set>
#include <vector>

class Solution { // Jul 31, 2025
public:
  int subarrayBitwiseORs(std::vector<int>& arr) {
    std::unordered_set<int> result;
    std::set<int> current;

    for (int num : arr) {
      std::set<int> next;
      next.insert(num);

      for (int x : current) {
        next.insert(x | num);
      }

      current = next;

      for (int x : current) {
        result.insert(x);
      }
    }

    return result.size(); 
  }
};
