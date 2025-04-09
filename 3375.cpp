#include <iostream>
#include <queue>
#include <set>

class Solution { // Apr 09, 2025 - Was in a rush
public:
  int minOperations(std::vector<int>& nums, int k) {
    std::priority_queue<int> numsHeap;
    std::set<int> inserted;
    for (int n : nums) {
      if(n < k) return -1;
      if(inserted.find(n) == inserted.end()) {
        numsHeap.push(n);
        inserted.insert(n);
      }
    }

    int count = 0;
    while(numsHeap.top() > k && !numsHeap.empty()) {
      int curr = numsHeap.top();
      std::cout << curr << "\n";
      numsHeap.pop();
      count++;
    }

    return count;
  }
};
