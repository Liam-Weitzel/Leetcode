#include <numeric>
#include <set>
#include <utility>
#include <vector>

class Solution {
public:
  int missingInteger(std::vector<int>& nums) { // Aug 11, 2026
    /*
    std::vector<int> prefixSumX(nums.size());
    std::vector<int> prefixSumI(nums.size());
    prefixSumI[0] = nums[0];
    for(int i = 1; i < nums.size(); i++) {
      prefixSumX[i] = nums[i-1] + prefixSumX[i-1];
      prefixSumI[i] = nums[i] + prefixSumI[i-1];
    }

    int cur = 0;
    std::pair<int, int> maxSeq;

    for(int i = 1; i < nums.size(); i++) {
      if(nums[i] != nums[i-1]+1) {
        int curSize = (i-1) - cur;
        int maxSize = maxSeq.second - maxSeq.first;
        if(curSize > maxSize) {
          maxSeq = std::make_pair(cur, i-1);
        } else if (curSize == maxSize) {
          int curSum = prefixSumI[i-1]-prefixSumX[cur];
          int maxSum = prefixSumI[maxSeq.second]-prefixSumX[maxSeq.first];
          if(curSum < maxSum) maxSeq = std::make_pair(cur, i-1);
        }
        cur = i;
      }
    }
    int curSize = (nums.size()-1) - cur;
    int maxSize = maxSeq.second - maxSeq.first;
    if(curSize > maxSize) {
      maxSeq = std::make_pair(cur, nums.size()-1);
    } else if (curSize == maxSize) {
      int curSum = prefixSumI[nums.size()-1]-prefixSumX[cur];
      int maxSum = prefixSumI[maxSeq.second]-prefixSumX[maxSeq.first];
      if(curSum > maxSum) maxSeq = std::make_pair(cur, nums.size()-1);
    }

    int maxSum = prefixSumI[maxSeq.second]-prefixSumX[maxSeq.first];
    std::cout << maxSeq.first << " " << maxSeq.second << " " << prefixSumX[maxSeq.first] << " " << prefixSumI[maxSeq.second] << " " << maxSum << std::endl;
    
    std::set<int> set(nums.begin(), nums.end());
    while(set.contains(maxSum)) maxSum++;

    // I see i made it waay too complicated.. Its only longest sequential PREFIX.... Not anywhere in the array...
    */

    int sum = nums[0];
    for(int i = 1; i < nums.size(); i++) {
      if(nums[i] != nums[i-1]+1) break;
      sum+=nums[i];
    }

    std::set<int> set(nums.begin(), nums.end());
    while(set.contains(sum)) sum++;

    return sum;
  }
};
