#include <numeric>
#include <vector>

class NumArrayMinMem { // Sep 17, 2026
private:
  std::vector<int>* nums;
public:
  NumArrayMinMem(std::vector<int>& nums) {
    this->nums = &nums;
  }
  
  int sumRange(int left, int right) {
    return std::accumulate(nums->begin()+left, nums->begin()+right+1, 0);
  }
};

class NumArray { // Sep 17, 2026
private:
  std::vector<int>* prefixSum;
  int sum = 0;
public:
  NumArray(std::vector<int>& nums) {
    prefixSum = new std::vector<int>(nums.size(), 0);
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
      prefixSum->at(i) = sum;
      sum += nums[i];
    }
    this->sum = sum;
  }
  
  int sumRange(int left, int right) {
    if(right+1 >= prefixSum->size()) return this->sum - prefixSum->at(left);
    return prefixSum->at(right+1) - prefixSum->at(left);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
