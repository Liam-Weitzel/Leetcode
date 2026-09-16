#include "utils/ListNode.h"

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

class Solution { // Sep 16, 2026
public:
  ListNode* removeElements(ListNode* head, int val) {
    //just remove val from linked list.

    ListNode* dummy = new ListNode(0, head);
    ListNode* iter = head;
    ListNode* prev = dummy;

    while(iter) {
      if(iter->val == val) {
        prev->next = iter->next;
      } else {
        prev = iter;
      }
      iter = iter->next;
    }

    return dummy->next;
  }
};
