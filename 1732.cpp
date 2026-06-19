#include <vector>

class Solution { // Jun 19, 2026
public:
  int largestAltitude(std::vector<int>& gain) {
    int altitude = 0, max_altitude = 0;
    for(int i : gain) {
      altitude += i;
      max_altitude = std::max(max_altitude, altitude);
    }
    return max_altitude;
  }
};
