//COMPILED USING: g++ 2196.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 2196

#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { // Jul 15, 2024
public:
  TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
    std::unordered_map<int, std::pair<int, int>> adjacencyMap;
    std::set<int> parents;
    std::set<int> children;
    for(std::vector<int> i : descriptions) {
      if(i[2]) adjacencyMap[i[0]].first = i[1];
      else adjacencyMap[i[0]].second = i[1];
      parents.insert(i[0]);
      children.insert(i[1]);
    }

    int root;
    for(auto i = parents.begin(); i != parents.end(); i++) {
      if(children.find(*i) == children.end()) root = *i;
    }

    TreeNode* head = new TreeNode(root);
    std::queue<TreeNode*> q;
    q.push(head);
    while(!q.empty()) {

      std::pair<int, int> curr = adjacencyMap[q.front()->val];

      if(curr.first != 0) {
        TreeNode* left = new TreeNode(curr.first);
        q.front()->left = left;
        q.push(left);
      }

      if(curr.second != 0) {
        TreeNode* right = new TreeNode(curr.second);
        q.front()->right = right;
        q.push(right);
      }

      q.pop();
    }

    return head;
  }
};

  void testSolution(std::vector<std::vector<int>> descriptions, std::vector<int> expected) {
  TreeNode* expectedTree = TreeFactory::CreateTree(expected);
  Solution solution;
  TreeNode* res = solution.createBinaryTree(descriptions);

  bool correct = true;
  std::queue<TreeNode*> qRes;
  std::queue<TreeNode*> qExpected;
  qRes.push(res);
  qExpected.push(expectedTree);
  while(!qRes.empty() && !qExpected.empty()) {
    if(qRes.front()->val != qExpected.front()->val) {
      correct = false;
      break;
    } else {
      if(qRes.front()->left) qRes.push(qRes.front()->left);
      if(qRes.front()->right) qRes.push(qRes.front()->right);
      if(qExpected.front()->left) qExpected.push(qExpected.front()->left);
      if(qExpected.front()->right) qExpected.push(qExpected.front()->right);
      qExpected.pop();
      qRes.pop();
    }
  }

  if(correct) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Descriptions: " << std::endl;
  for(std::vector<int> i : descriptions) std::cout << i[0] << ", " << i[1] << ", " << i[2] << std::endl;
  std::cout << std::endl;

  std::cout << "Output: " << std::endl;
  TreePrinter::PrintTree(res);
  std::cout << std::endl;

  std::cout << "Expected: " << std::endl;
  TreePrinter::PrintTree(expectedTree);
  std::cout << std::endl << "\033[0m" << "------------------" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}}, {50,20,80,15,17,19});
  testSolution({{1,2,1},{2,3,0},{3,4,1}}, {1,2,-1,-1,3,4});
}
