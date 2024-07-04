//COMPILED USING: g++ 2181.cpp utils/ListFactory.cpp utils/ListPrinter.cpp -o 2181

#include "utils/ListNode.h"
#include "utils/ListPrinter.h"
#include "utils/ListFactory.h"
#include <iostream>
#include <vector>

class Solution { // Jul 04, 2024
public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* res = new ListNode();
    ListNode* currNode = res;
    int currSum = 0;
    while(head) {
      if(head->val == 0) {
        currNode->next = new ListNode();
        currNode = currNode->next;
        currNode->val = currSum;
        currSum = 0;
      } else {
        currSum += head->val;
      }
      head = head->next;
    }
    return res->next->next;
  }
};

void testSolution(std::vector<int> headVec, std::vector<int> expectedVec) {
  ListNode* head = ListFactory::CreateList(headVec);
  ListNode* expected = ListFactory::CreateList(expectedVec);
  Solution res;
  ListNode* Res = res.mergeNodes(head);

  ListNode* copyRes = Res;
  ListNode* copyExpected = expected;
  bool equal = true;
  while(copyRes && copyExpected) {
    if(copyRes->val != copyExpected->val) equal = false;
    copyRes = copyRes->next;
    copyExpected = copyExpected->next;
  }

  if(equal) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << std::endl << "Input: ";
  ListPrinter::PrintList(head);
  std::cout << std::endl;

  std::cout << "Output: ";
  ListPrinter::PrintList(Res);
  std::cout << std::endl;

  std::cout << "Expected: ";
  ListPrinter::PrintList(expected);
  std::cout << "\033[0m" << std::endl;
  std::cout << "--------------------------" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({0,3,1,0,4,5,2,0}, {4,11});
  testSolution({0,1,0,3,0,2,2,0}, {1,3,4});
}
