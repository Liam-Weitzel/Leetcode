#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <vector>

class Solution { // Aug 04, 2025
public:
  int totalFruit(std::vector<int>& fruits) {
    int left = 0;
    std::set<int> pickedFruits;
    std::map<int, int> lastSeen;
    int max = INT_MIN;
    for(int right = 0; right < fruits.size(); right++) {
      lastSeen[fruits[right]] = right;
      if(pickedFruits.size() < 2) {
        pickedFruits.insert(fruits[right]);
      } else if (pickedFruits.contains(fruits[right])) {
        // Nothing - just advance right ptr
      } else if(!pickedFruits.contains(fruits[right])) {
        pickedFruits.insert(fruits[right]);
        std::vector<int> lastSeenFruitPos;
        for(int i : pickedFruits) lastSeenFruitPos.push_back(lastSeen[i]);
        int fruitToRemove = *std::min_element(lastSeenFruitPos.begin(), lastSeenFruitPos.end());
        pickedFruits.erase(fruits[fruitToRemove]);
        left = fruitToRemove+1;
      }
      max = std::max(right-left+1, max);
    }
    return max;
  }
};
