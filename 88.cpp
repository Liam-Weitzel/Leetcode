#include <climits>
#include <vector>

class Solution { // Jul 08, 2026
public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {

    std::vector<int> res;
    res.reserve(m+n);

    int ptr1 = 0;
    int ptr2 = 0;
    int n1 = m-1;
    int n2 = n-1;

    while(ptr1 <= n1 || ptr2 <= n2) {
      int cur1 = INT_MAX;
      if(ptr1 <= n1) cur1 = nums1[ptr1];
      int cur2 = INT_MAX;
      if(ptr2 <= n2) cur2 = nums2[ptr2];
      int max = std::min(cur1, cur2);
      if(max == cur1) {
        res.push_back(cur1);
        ptr1++;
      }
      else if(max == cur2) {
        res.push_back(cur2);
        ptr2++;
      }
    }
    nums1 = res;
  }
};
