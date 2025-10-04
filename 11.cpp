#include <vector>

class Solution { // Oct 04, 2025
public:
  int maxArea(std::vector<int>& height) {
    int left = 0;
    int right = height.size()-1;
    int maxArea = 0;
    while(left < right) {
      int smallest = std::min(height[left], height[right]);
      maxArea = std::max(maxArea, (right-left) * smallest);
      if(height[left] == smallest) left++;
      else if (height[right] == smallest) right--;
      else {
        right--;
      }
    }
    return maxArea;
  }
};
