#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

class Solution { // Mar 02, 2024
private:
  int findMin(int left, int right, std::vector<int>& nums) {
      int mid;
      while (right-left > 1) {
      mid = (left+right)/2;
      if(abs(nums[mid]) < abs(nums[mid+1])) {
        right = mid;
      }
      else if (abs(nums[mid]) > abs(nums[mid+1])) {
        left = mid;
      } else if (abs(nums[mid]) > abs(nums[mid-1])) {
        right = mid;
      } else if (abs(nums[mid]) < abs(nums[mid-1])) {
        left = mid;
      } else {
        int rightRec = findMin(left, mid, nums);
        int leftRec = findMin(mid, right, nums);
        if(abs(nums[rightRec]) >= abs(nums[leftRec])) return leftRec;
        if(abs(nums[rightRec]) < abs(nums[leftRec])) return rightRec;
      }
    }
    return mid;
  }

public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> res;
    if(n <= 2) {
      if(n == 1) {
        res.push_back(nums[0]*nums[0]);
        return res;
      }
      if(n == 2) {
        if(abs(nums[0]) > abs(nums[1])) {
          res.push_back(nums[1]*nums[1]);
          res.push_back(nums[0]*nums[0]);
        } else {
          res.push_back(nums[0]*nums[0]);
          res.push_back(nums[1]*nums[1]);
        }
        return res;
      }
    }

    int mid = findMin(0, n-1, nums);
        
    int negPtr = mid-1;
    int posPtr = mid;
    if(mid+1 < n && abs(nums[mid]) > abs(nums[mid+1])) {
      negPtr = mid;
      posPtr = mid+1;
    }
        
    while (negPtr >= 0 || posPtr < n) {
      if(posPtr == n || (negPtr >= 0 && abs(nums[negPtr]) < abs(nums[posPtr]))) {
        res.push_back(nums[negPtr]*nums[negPtr]);
        negPtr--;
      } else if (negPtr == -1 || (posPtr < n && abs(nums[negPtr]) >= abs(nums[posPtr]))) {
        res.push_back(nums[posPtr]*nums[posPtr]);
        posPtr++;
      }
    }
    return res;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> nums = {-15, -11, -5, -2, -2, 2, 3, 5, 15};
  for(int i : res->sortedSquares(nums)) std::cout << i << ", " << std::endl;
  return 0;
}
