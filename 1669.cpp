//COMPILED USING: g++ 1669.cpp utils/ListFactory.cpp utils/ListPrinter.cpp -o 1669

#include "utils/ListNode.h"
#include "utils/ListFactory.h"
#include "utils/ListPrinter.h"
#include <iostream>
#include <memory>

class Solution { // Mar 20, 2024
public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* list2end = list2;
    while(list2end->next) list2end = list2end->next;
    
    ListNode* list1atA = list1;
    for(int i = 0; i < a-1; ++i) list1atA = list1atA->next;
    
    ListNode* list1atB = list1;
    for(int i = 0; i < b+1; ++i) list1atB = list1atB->next;

    list1atA->next = list2;
    list2end->next = list1atB;

    return list1;
  }
};

int main (int argc, char *argv[]) {
  ListNode* list1 = ListFactory::CreateList({10,1,13,6,9,5});
  std::cout << "List1: ";
  ListPrinter::PrintList(list1);
  ListNode* list2 = ListFactory::CreateList({1000000,1000001,1000002});
  std::cout << "List2: ";
  ListPrinter::PrintList(list2);
  int a = 3;
  int b = 4;
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << "Res: ";
  ListPrinter::PrintList(res->mergeInBetween(list1, a, b, list2));
  return 0;
}
