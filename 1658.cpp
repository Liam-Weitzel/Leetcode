#include <algorithm>
#include <numeric>
#include <vector>
class Solution {
public:
  int minOperations(std::vector<int>& nums, int x) { // Sep 23, 2026
    // You are given an integer array nums and an integer x.
    // In one operation, you can either remove the leftmost or the rightmost
    // element from the array nums and subtract its value from x.
    // Note that this modifies the array for future operations.

    // Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

    // Example 1:
    // Input: nums = [1,1,4,2,3], x = 5
    // Output: 2
    // Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

    // Example 2:
    // Input: nums = [5,6,7,8,9], x = 4
    // Output: -1

    // Example 3:
    // Input: nums = [3,2,20,1,1,3], x = 10
    // Output: 5
    // Explanation: The optimal solution is to remove the last three elements and
    // the first two elements (5 operations in total) to reduce x to zero.

    // BRUTE FORCE:
    // we can only remove right and left, so we can do a BFS across the binary tree.
    // stop condition is when we reach <0, return num of steps if we reach 0 exactly.
    // no need to memoize as every series of steps that leads to the same state are always the exact same as the previously explored state.
    // Time complexity: O(2^n)

    // SLIDING WINDOW:
    // if we flip the array inside out:
    // 5, 6, 7, 8, 9, 10 -> 7, 6, 5, 10, 9, 8
    // now we can start a sliding window from the middle and always have a valid order.
    // our goal becomes finding the minimum range that sums up to x.
    // instead of flippig the array inside out, we can also take the sum once and then think about the ELEMENTS we will keep in the array.
    // - removing some elements from the left
    // - and some elements from the right
    // - leaves one contiguous middle subarray
    // so instead of trying to make the removable elements contiguous, we make the non removed elements contigious.
    // then we just do the sum of the whole array - sum of the unremoved = x and find the BIGGEST window which allows for this.
    // so target = total sum - x
    // left = 0
    // right = 0
    // sum = 0
    // if sum < target, make the window bigger by moving right
    // if sum > target, make the window smaller by moving left
    // if sum == target, record the window length, then continue
    // Time complexity: O(n)

    int target = std::accumulate(nums.begin(), nums.end(), 0) - x;

    if (target < 0) return -1;

    int left = 0;
    int sum = 0;
    int maxSize = -1;

    for (int right = 0; right < nums.size(); ++right) {
      sum += nums[right];
      while (sum > target) sum -= nums[left++];
      if (sum == target) maxSize = std::max(maxSize, right - left + 1);
    }

    if(maxSize == -1) return -1;

    return nums.size()-maxSize;
  }
};
