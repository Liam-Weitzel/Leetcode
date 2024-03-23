//COMPILED USING: g++ 143.cpp utils/ListFactory.cpp utils/ListPrinter.cpp -o 143

#include "utils/ListNode.h"
#include "utils/ListFactory.h"
#include "utils/ListPrinter.h"
#include <memory>

class Solution { // Mar 23, 2024
public:
  void reorderList(ListNode* head) {
    //Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    //Reverse second half
    ListNode* prev = nullptr;
    ListNode* curr = slow;
    ListNode* next = nullptr;
    while(curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    //Add alternating into first half
    ListNode* front = head;
    ListNode* back = prev;
    while(front->next && back->next) {
      ListNode* front_next = front->next;
      front->next = back;
      ListNode* back_next = back->next;
      back->next = front_next;
      back = back_next;
      front = front_next;
    }
  }
};

int main (int argc, char *argv[]) {
  ListNode* head = ListFactory::CreateList({1,2,3,4,5,6,7,8,9});
  ListPrinter::PrintList(head);
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  res->reorderList(head);
  ListPrinter::PrintList(head);
  return 0;
}
