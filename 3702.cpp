#include <numeric>
#include <vector>

class Solution { // Aug 15, 2026
public:
  int longestSubsequence(std::vector<int>& nums) {
    //if you do 1 xor 2 xor 3 and then xor 1 again
    //its the same as 2 xor 3, this is crucial for sliding window
    // 001 ^ 010 = 011
    // 011 ^ 011 = 000
    // (000 ^ 001 = 001) == (010 ^ 011 = 001)
    // how are we going to do the sliding window? its asking for a subsequence
    // a subsequence is an array you can make by deleting x amounts of elements
    // we don't take a sliding window approach, we take the entire array and the selectively remove 1 element...
    if(std::accumulate(nums.begin(), nums.end(), 0LL) == 0) return 0;
    int cur = 0;
    for(int i : nums) cur = cur ^ i;
    if(cur != 0) return nums.size();
    return nums.size()-1;
  }
};

