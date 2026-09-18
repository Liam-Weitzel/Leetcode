#include <cmath>
#include <vector>

class Solution { // Sep 18, 2026
public:
  std::vector<int> constructRectangle(int area) {
    // The area of the rectangular web page you designed must equal to the given target area.
    // The width W should not be larger than the length L, which means L >= W.
    // The difference between length L and width W should be as small as possible.
    // Return an array [L, W] where L and W are the length and width of the web page you designed in sequence.
    //
    // create a rectange of area 'area' where L >= W && difference between L and W should be minimized.
    // so isn't it always that L=W? but then we can only get squares of 2 area wise.
    // if area is not a power of 2, we go to the nearest lowest and increment from there? or binary search?
    // A = L * W
    // so we can also do this:
    // L = A/1...2...3...4...5...6...7 until we find the smallest, then we can binary search... the max would be when W is larger than L...
    //
    // lets check if this is true
    // A = 6
    // intuitively i say: W2*L3
    // L = 6/1; L = 6
    // L = 6/2; L = 3
    // L = 6/3; L = 2 (CAN'T HAPPEN AS 3 >= 2)
    //
    // another example:
    // A = 56;
    // L = 56/1; L = 56;
    // L = 56/2; L = 28;
    // L = 56/3; L = 18; (not int)
    // L = 56/4; L = 14;
    // L = 56/5; L = 11; (not int)
    // L = 56/6; L = 9; (not int)
    // L = 56/7; L = 8; (not int)
    // L = 56/8; L = 7; (CAN'T HAPPEN AS 8 >= 7)
    //
    // Maybe there is an easier way?
    // L = Area/W
    // W = Area/L
    // we can just start in the perfect square situation and then move down.
    // the perfect square solution is the sqrt of area...

    int W = std::sqrt(area);

    while (area % W != 0) W--;

    return {area / W, W};
  }
};
