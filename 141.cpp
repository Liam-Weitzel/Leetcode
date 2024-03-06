#include "utils/ListNode.h"
#include "utils/ListFactory.h"
#include "utils/ListPrinter.h"
#include <iostream>
#include <memory>
#include <vector>

class Solution { // Mar 06, 2024
public:
  bool hasCycle(ListNode *head) {
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    while(fastPtr && fastPtr->next && fastPtr->next->next) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;
      if(fastPtr == slowPtr) return true;
    }

    return false;
  }
};

int main (int argc, char *argv[]) {
  ListNode *head = ListFactory::CreateList({3,2,4,5,7,53,1,2,5,7,8,9,8,78,7878,45,54,3,132,4,4578,78,456,123,2,12345,45,78,456,123,45,78,547,45,123,123,45,78,457,524,12});
  ListPrinter::PrintList(head);

  ListNode *toConnectToEnd = head;
  for(int i = 0; i < 5; ++i) toConnectToEnd = toConnectToEnd->next;
  ListNode *end = head;
  while(end->next) end = end->next;
  end->next = toConnectToEnd;

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->hasCycle(head) << std::endl;
  return 0;
}
