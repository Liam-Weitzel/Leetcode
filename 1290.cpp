//COMPILED USING: g++ 100.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 100

#include "utils/ListNode.h"
#include "utils/ListFactory.h"
#include "utils/ListPrinter.h"
#include <cstdint>
#include <iostream>

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

class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int size = 0;
    ListNode* node = head;

    while(node != nullptr) {
      size++;
      node = node->next;
    }

    uint32_t res = 0;
    node = head;
    int pos = size - 1;

    while(node != nullptr) {
      if(node->val) {
        res |= ((uint32_t)1 << pos);
      }
      pos--;
      node = node->next;
    }

    return res;
  }
};

void testSolution(ListNode* head, int expected) {
  Solution res;
  int ans = res.getDecimalValue(head);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Head: ";
  ListPrinter::PrintList(head);

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(ListFactory::CreateList({1, 0, 1}), 5);
  testSolution(ListFactory::CreateList({0}), 0);
}
