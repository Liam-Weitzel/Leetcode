#include <climits>
#include <vector>

class Solution { // Sep 03, 2026
public:
  bool uniformArray(std::vector<int>& nums1) {
    //find ONLY the 2 smallest odd. consists of distinct integers so we dont need to track index
    //reason we only need the 2 smallest odd:
    //even-even = even
    //odd-odd = even
    //odd-even = odd
    //even-odd = odd
    //with 1 odd we would be able to turn ALL odds into evens and all evens into odds... but the problem specifically states that j != i...
    //so we need the second smallest odd to turn THAT first smallest odd into an even.
    std::pair<int, int> smallestOdd = std::make_pair(INT_MAX, INT_MAX);

    for(int i : nums1) {
      if(i%2!=0)
        if(i < smallestOdd.first) {
          smallestOdd.second = smallestOdd.first;
          smallestOdd.first = i;
        } else if (i < smallestOdd.second) {
          smallestOdd.second = i;
        }
    }

    int possibleOddCount = 0;
    int possibleEvenCount = 0;
    for(int i : nums1) {
      if(i%2==0) {
        possibleEvenCount++;
        if(i-smallestOdd.first >= 1) possibleOddCount++;
      }else{
        possibleOddCount++;
        if(i != smallestOdd.first && i-smallestOdd.first >= 1) possibleEvenCount++;
        else if (i == smallestOdd.first && i-smallestOdd.second >= 1) possibleEvenCount++;
      }
    }

    return possibleOddCount == nums1.size() || possibleEvenCount == nums1.size();
  }
};
