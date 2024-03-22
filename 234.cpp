 //COMPILED USING: g++ 234.cpp utils/ListFactory.cpp utils/ListPrinter.cpp -o 234

#include "utils/ListNode.h"
#include "utils/ListFactory.h"
#include "utils/ListPrinter.h"
#include <iostream>
#include <memory>

class Solution { // Mar 22, 2024
public:
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    //find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    //if odd, skip past the middle
    if(fast) slow = slow->next;

    //reverse from middle
    ListNode* prev = nullptr;
    ListNode* curr = slow;
    ListNode* next = nullptr;
    while(curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    //iterate through both halves and check if they are equal
    ListNode* firstHalf = head;
    ListNode* secondHalf = prev;
    while(firstHalf && secondHalf) {
      if(firstHalf->val != secondHalf->val) return false;
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    return true;
  }
};

int main (int argc, char *argv[]) {
  ListNode* head = ListFactory::CreateList({1,1,2,2,2,1,1});
  ListPrinter::PrintList(head);
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->isPalindrome(head) << std::endl;
  return 0;
}
