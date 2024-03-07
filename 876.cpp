//COMPILED USING: g++ 876.cpp utils/ListFactory.cpp utils/ListPrinter.cpp -o 876

#include "utils/ListNode.h"
#include "utils/ListFactory.h"
#include "utils/ListPrinter.h"
#include <memory>
#include <vector>

class Solution { // Mar 07, 2024
public:
  ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    int iter = 0;

    while(fast->next) {
      fast = fast->next;
      iter++;
      if(iter%2 == 0) slow = slow->next;
    }

    return slow;
  }
};

int main (int argc, char *argv[]) {
  ListNode* head = ListFactory::CreateList({1,2,3,4,5});
  ListPrinter::PrintList(head);
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  ListPrinter::PrintList(res->middleNode(head));
  return 0;
}
