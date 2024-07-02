#include <iostream>
#include <map>
#include <vector>

class Solution { // Jul 02, 2024
public:
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::map<int, int> nums1FreqCount;
    for(int i : nums1) nums1FreqCount[i]++;

    std::vector<int> res;
    for(int i : nums2) {
      if(nums1FreqCount[i] > 0) {
        res.push_back(i);
        nums1FreqCount[i]--;
      }
    }

    return res;
  }
};

void testSolution(std::vector<int> nums1, std::vector<int> nums2, std::vector<int> expected) {
  Solution res;
  std::vector<int> ans = res.intersect(nums1, nums2);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Input: " << std::endl;
  for(int i : nums1) std::cout << i << ", ";
  std::cout << std::endl;
  for(int i : nums2) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: ";
  for(int i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Epected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,2,2,1}, {2,2}, {2,2});
  testSolution({4,9,5}, {9,4,9,8,4}, {9,4});
}
