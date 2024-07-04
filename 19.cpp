//COMPILED USING: g++ 19.cpp utils/ListFactory.cpp utils/ListPrinter.cpp -o 19

#include "utils/ListNode.h"
#include "utils/ListPrinter.h"
#include "utils/ListFactory.h"
#include <vector>
#include <memory>

class Solution { // Mar 03, 2024
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* prependHead = new ListNode(0, head);
    ListNode* slowPtr = prependHead, *fastPtr = prependHead;
    int afkTimer = 0;

    while(fastPtr->next) {
      if(afkTimer >= n) slowPtr = slowPtr->next;
      fastPtr = fastPtr->next;
      afkTimer++;
    }

    if(slowPtr->next == head) head = head->next;
    else slowPtr->next = slowPtr->next->next;
    return head;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> values = {1, 2, 3, 4, 5};
  ListNode* list = ListFactory::CreateList(values);
  ListPrinter::PrintList(list);

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  list = res->removeNthFromEnd(list, 2);
  ListPrinter::PrintList(list);
  
  return 0;
}
