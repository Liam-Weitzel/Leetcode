#include <vector>

class Solution { // Sep 14, 2026
public:
  bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
    // There is a simple geometry way of doing this but i forgot :)

    if(rec1 == rec2) return true;

    bool xOverlap = false;
    if(rec1[0] < rec2[0] && rec2[0] < rec1[2]) xOverlap = true;
    if(rec2[0] < rec1[0] && rec1[0] < rec2[2]) xOverlap = true;
    if(rec1[2] > rec2[2] && rec2[2] > rec1[0]) xOverlap = true;
    if(rec2[2] > rec1[2] && rec1[2] > rec2[0]) xOverlap = true;

    bool yOverlap = false;
    if(rec1[1] < rec2[1] && rec2[1] < rec1[3]) yOverlap = true;
    if(rec2[1] < rec1[1] && rec1[1] < rec2[3]) yOverlap = true;
    if(rec1[3] > rec2[3] && rec2[3] > rec1[1]) yOverlap = true;
    if(rec2[3] > rec1[3] && rec1[3] > rec2[1]) yOverlap = true;

    return xOverlap && yOverlap;

    // its return r1[2]>r2[0] && r2[2]>r1[0] && r1[3]>r2[1] && r2[3]>r1[1];...
    // anyhow still O(1)...
  }
};
