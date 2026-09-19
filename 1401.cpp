#include <algorithm>
#include <cmath>

class Solution { // Sep 19, 2026
public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    //1. find closest point of the square to the center of the circle
    //2. check if the distance between these points is less than or equal to radius
    // to find the closest point of the square to the center of the circle we just set x and y to circle center x any y clamped by the squares area
    // then distance between two points sqrt{(x2-x1)^2+(y2-y1)^2)} <= radius.
    int xClosest = std::clamp(xCenter, x1, x2);
    int yClosest = std::clamp(yCenter, y1, y2);
    int distance = std::sqrt(std::pow(xCenter-xClosest, 2)+std::pow(yCenter-yClosest,2));
    if(distance <= radius) return true;
    return false;
  }
};
