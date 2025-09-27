#include <climits>
#include <cstdlib>
#include <vector>

class Solution { // Sep 27, 2025
private:
  double triangleArea(double x1, double y1,
                      double x2, double y2,
                      double x3, double y3) {
    return 0.5 * std::abs(
      x1 * (y2 - y3) +
      x2 * (y3 - y1) +
      x3 * (y1 - y2)
    );
  }
public:
  double largestTriangleArea(std::vector<std::vector<int>>& points) {
    double max = INT_MIN;
    for(int i = 0; i < points.size(); i++) {
      for(int j = i+1; j < points.size(); j++) {
        for(int z = j+1; z < points.size(); z++) {
          max = std::max(max, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[z][0], points[z][1]));
        }
      }
    }
    return max;
  }
};
