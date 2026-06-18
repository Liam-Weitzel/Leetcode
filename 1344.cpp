#include <algorithm>
#include <cstdlib>

class Solution { // Jun 18, 2026
public:
  double angleClock(int hour, int minutes) {
    double hour_angle = (hour % 12) * 30.0;
    int minute_angle = minutes * 6;
    double hour_min_angle = hour_angle + (0.5 * minutes);
    double diff = std::abs(hour_min_angle - minute_angle);
    return std::min(diff, 360.0 - diff);
  }
};
