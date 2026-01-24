#include <iostream>
#include <vector>

class Solution { // Jan 24, 2026
private:
  int searchSubArray(std::vector<int> nums, int target, int begin, int end) {
    int left = begin;
    int right = end;
    int mid = (left + right) / 2;
    
    while(left != right) {
      if(nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
      mid = (left + right) / 2;
    }

    if(nums[mid] == target) return mid;
    return -1;
  }

public:
  int search(std::vector<int> nums, int target) {
    //find pivot using previous impl
    int n = nums.size();
    int left = 0;
    int right = n-1;
    int mid = (left + right) / 2;

    while(left != right) {
      if(nums[mid] >= nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
      mid = (left + right) / 2;
    }

    if(nums[mid] > nums[0]) mid = nums[0];

    //mid is now the index of the lowest number / pivot
    //then do binary search on the part that contains the target
    if(target <= nums[n-1]) {
      //target is in second part
      return searchSubArray(nums, target, mid, n-1);
    } else {
      //target is in first part
      return searchSubArray(nums, target, 0, mid);
    }
  }
};

void testSolution(std::vector<int> nums, int target, int expected) {
  Solution res;
  int ans = res.search(nums, target);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Target: " << target << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({4,5,6,7,0,1,2}, 0, 4);
  testSolution({0,1,2,4,5,6,7}, 4, 3);
  testSolution({8,0,1,2,4,5,6,7}, 8, 0);
  testSolution({1}, 0, -1);
  testSolution({2,1}, 0, -1);
}
