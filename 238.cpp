#include <iostream>
#include <memory>
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

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> nums = {1,2,3,4,5,6,7,8,9};
  for(int i : res->productExceptSelf(nums)) std::cout << i << ", ";
  std::cout << std::endl;
  return 0;
}
