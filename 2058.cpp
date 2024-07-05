//COMPILED USING: g++ 2058.cpp utils/ListFactory.cpp utils/ListPrinter.cpp -o 2058

#include "utils/ListNode.h"
#include "utils/ListFactory.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution { // Jul 05, 2024
public:
  std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* prevNode = head;
    int currIndex = 1;
    std::vector<int> indicesOfCriticalPoints;
    while(head->next) {
      if((prevNode->val > head->val && head->next->val > head->val) || (prevNode->val < head->val && head->next->val < head->val)) {
        indicesOfCriticalPoints.push_back(currIndex);
      }
      prevNode = head;
      head = head->next;
      currIndex++;
    }

    if(indicesOfCriticalPoints.size() < 2) return {-1, -1};

    int maxDist = *std::max_element(indicesOfCriticalPoints.begin(), indicesOfCriticalPoints.end()) - *std::min_element(indicesOfCriticalPoints.begin(), indicesOfCriticalPoints.end());

    int minDist = INT_MAX;
    int prev = INT_MAX;
    for(int i : indicesOfCriticalPoints) {
      if(std::abs(i-prev) < minDist) minDist = std::abs(i-prev);
      prev = i;
    }
    
    return { minDist, maxDist};
  }
};

void testSolution(std::vector<int> head, std::vector<int> expected) {
  ListNode* headL = ListFactory::CreateList(head);
  Solution res;
  std::vector<int> Res = res.nodesBetweenCriticalPoints(headL);

  if(Res == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << std::endl << "Input: ";
  for(int i : head) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: ";
  for(int i : Res) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << std::endl << std::endl << "--------------------------";
  std::cout << "\033[0m" << std::endl ;
}

int main (int argc, char *argv[]) {
  testSolution({3,1}, {-1,-1});
  testSolution({5,3,1,2,5,1,2}, {1,3});
  testSolution({1,3,2,2,3,2,2,2,7}, {3,3});
}
