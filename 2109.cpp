#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

struct ListNode {
  char val;
  ListNode *next;
  ListNode() : val(' '), next(nullptr) {}
  ListNode(char x) : val(x), next(nullptr) {}
  ListNode(char x, ListNode *next) : val(x), next(next) {}
};

class Solution { // Dec 03, 2024
public:
  std::string addSpaces(std::string s, std::vector<int>& spaces) {
    //Linked list approach: O(n + m(log(m)))
    //Naive approach: O(n*m(log(m)))

    ListNode* head = new ListNode();
    ListNode* iter = head;
    for(char i : s) {
      ListNode* temp = new ListNode(i);
      iter->next = temp;
      iter = iter->next;
    }
    head = head->next;

    std::sort(spaces.begin(), spaces.end());

    std::vector<int> diffBetweenSpaces = {spaces[0]};
    for(int i = 1; i < spaces.size(); i++) {
      diffBetweenSpaces.push_back(spaces[i]-spaces[i-1]);
    }

    iter = head;
    for(int nextSpace : diffBetweenSpaces) {
      for(int i = 0; i < nextSpace; i++) {
        iter = iter->next;
      }
      ListNode* space = new ListNode(' ', iter->next);
      iter->next = space;
    }

    ListNode* copy = head;
    while(copy) {
      std::cout << copy->val;
      copy = copy->next;
    }

    //NOTE: RAN OUT OF TIME

    return "";
  }
};

void testSolution(std::string s, std::vector<int> spaces, std::string expected) {
  Solution res;
  std::string ans = res.addSpaces(s, spaces);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "S: \"" << s << "\"" << std::endl;

  std::cout << "Spaces: ";
  for(int i : spaces) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Answer: \"" << ans << "\"" << std::endl;

  std::cout << "Expected: \"" << expected << "\"" << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("EnjoyYourCoffee", {5, 9}, "Enjoy Your Coffee");
  testSolution("LeetcodeHelpsMeLearn", {8, 13, 15}, "Leetcode Helps Me Learn");
  testSolution("icodeinpython", {1, 5, 7, 9}, "i code in py thon");
  testSolution("spacing", {0,1,2,3,4,5,6}, " s p a c i n g");
}
