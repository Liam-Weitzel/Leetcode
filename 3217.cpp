#include <set>
#include <vector>
#include "utils/ListNode.h"

class Solution { // Nov 01, 2025
public:
  ListNode *modifiedList(std::vector<int> &nums, ListNode *head) {
    ListNode *iter = head;
    ListNode *prev = head;
    std::set<int> numsSet(nums.begin(), nums.end());

    while (iter->next) {
      if (numsSet.find(iter->val) != numsSet.end()) {
        if (prev == head && iter == head) {
          head = iter->next;
          prev = head;
          iter = iter->next;
          continue;
        } else {
          prev->next = iter->next;
          iter = iter->next;
          continue;
        }
      }

      prev = iter;
      iter = iter->next;
    }

    if (numsSet.find(iter->val) != numsSet.end())
      prev->next = nullptr;

    return head;
  }
};
