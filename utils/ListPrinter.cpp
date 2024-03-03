#include "ListPrinter.h"
#include <iostream>

void ListPrinter::PrintList(ListNode* node) {
  while (node != nullptr) {
    std::cout << node->val;
    if (node->next != nullptr) std::cout << " -> ";
    node = node->next;
  }
  std::cout << std::endl;
}
