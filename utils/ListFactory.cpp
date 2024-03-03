#include "ListFactory.h"
#include <vector>

ListNode* ListFactory::CreateList(const std::vector<int>& values) {
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  for (int value : values) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  return head;
}
