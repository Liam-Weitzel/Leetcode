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

class Solution2 { // Jan 29, 2026
public:
  int maxArea(std::vector<int>& height) {
    // [1,6,7,5,5,4,8,3,7]
    // My intuitions says prefix max but breaks in previous case.
    // Two pointer approach? Increment the lower one? Record the max?
    int left = 0;
    int right = height.size()-1;
    int res = 0;
    while(left != right) {
      int distance = right - left;
      res = std::max(res, std::min(height[right], height[left]) * distance);
      if(height[left] > height[right])
        right--;
      else
        left++;
    }
    return res;
  }
};
