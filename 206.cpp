//COMPILED USING: g++ 206.cpp utils/ListFactory.cpp utils/ListPrinter.cpp -o 206

#include "utils/ListNode.h"
#include "utils/ListFactory.h"
#include "utils/ListPrinter.h"
#include <memory>

class Solution { // Mar 21, 2024
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *curr = head, *prev = nullptr, *next = nullptr;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

int main (int argc, char *argv[]) {
  ListNode* list = ListFactory::CreateList({1,2,3,4,5,6,7,8,9});
  ListPrinter::PrintList(list);
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  list = res->reverseList(list);
  ListPrinter::PrintList(list);
  return 0;
}
