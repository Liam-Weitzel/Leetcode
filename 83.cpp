/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "utils/ListNode.h"
#include <set>

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* i = head->next;
    ListNode* prev = head;
    std::set<int> seen;
    seen.insert(head->val);
    while(i) {
      if(seen.contains(i->val))
        prev->next = i->next;
      else {
        seen.insert(i->val);
        prev = i;
      }
      i = i->next;
    }
    return head;
  }
};
