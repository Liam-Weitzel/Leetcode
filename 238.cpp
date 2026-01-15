#include <iostream>
#include <vector>

class Solution { // Mar 15, 2024
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> prefixProduct(n, 1);
    std::vector<int> suffixProduct(n, 1);
    for(int i = 1; i < n; ++i) {
      prefixProduct[i] = prefixProduct[i-1]*nums[i-1];
    }
    for(int i = n-2; i >= 0; --i) {
      suffixProduct[i] = suffixProduct[i+1]*nums[i+1];
    }

    std::vector<int> res(n, 0);
    for(int i = 0; i < n; ++i) {
      res[i] = prefixProduct[i]*suffixProduct[i];
    }

    return res;
  }
};

class Solution2 { // Jan 15, 2026
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();

    std::vector<int> prefixProduct(n, 1);
    for(int i = 1; i < n; i++)
      prefixProduct[i] = prefixProduct[i-1]*nums[i-1];

    std::vector<int> suffixProduct(n, 1);
    for(int i = n-2; i >= 0; i--)
      suffixProduct[i] = suffixProduct[i+1]*nums[i+1];

    std::vector<int> res(n, 0);
    for(int i = 0; i < n; i++)
      res[i] = prefixProduct[i] * suffixProduct[i];

    return res;
  }
};

void testSolution(std::vector<int> nums, std::vector<int> expected) {
  Solution2 res;
  std::vector<int> ans = res.productExceptSelf(nums);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "nums: ";
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "ans: ";
  for(int i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,2,3,4}, {24,12,8,6});
  testSolution({-1,1,0,-3,3}, {0,0,9,0,0});
}
