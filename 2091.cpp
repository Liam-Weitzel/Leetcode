#include <algorithm>
#include <vector>

class Solution { // Aug 30, 2026
public:
  int minimumDeletions(std::vector<int>& nums) {
    auto min = std::min_element(nums.begin(), nums.end());
    auto max = std::max_element(nums.begin(), nums.end());
    int minDistanceFromBegin = std::distance(nums.begin(), min) + 1;
    int minDistanceFromEnd = std::distance(nums.end(), min) * -1;
    int maxDistanceFromBegin = std::distance(nums.begin(), max) + 1;
    int maxDistanceFromEnd = std::distance(nums.end(), max) * -1;

    //min and max are the same element
    if(min == max) return std::min(minDistanceFromBegin, minDistanceFromEnd);
    
    std::vector<int> possibilities;

    //remove min from left and max from right
    possibilities.push_back(minDistanceFromBegin + maxDistanceFromEnd);
    //remove min from right and max from left
    possibilities.push_back(minDistanceFromEnd + maxDistanceFromBegin);
    //remove min from left and max from left
    possibilities.push_back(std::max(minDistanceFromBegin, maxDistanceFromBegin));
    //remove min from right and max from right
    possibilities.push_back(std::max(minDistanceFromEnd, maxDistanceFromEnd));

    return *std::min_element(possibilities.begin(), possibilities.end());
  }
};
