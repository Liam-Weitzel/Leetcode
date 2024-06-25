//COMPILED USING: g++ 1038.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 1038

#include <iostream>
#include <queue>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { // Jun 25, 2024
private:
  int dfs(TreeNode* node, int currSum) {
    int sum = node->val;
    if(node->right) sum += dfs(node->right, currSum);
    node->val = currSum + sum;
    if(node->left) sum += dfs(node->left, currSum + sum);
    return sum;
  }

public:
  TreeNode* bstToGst(TreeNode* root) {
    dfs(root, 0);
    return root;
  }
};

void testSolution(std::vector<int> nums, std::vector<int> expected) {
  TreeNode* inputTree = TreeFactory::CreateTree(nums);

  std::cout << "Input:" << std::endl;
  TreePrinter::PrintTree(inputTree);
  std::cout << std::endl;

  TreeNode* expectedTree = TreeFactory::CreateTree(expected);
  Solution solution;
  TreeNode* res = solution.bstToGst(inputTree);

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

  std::cout << "Output:" << std::endl;
  TreePrinter::PrintTree(res);
  std::cout << std::endl;

  std::cout << "Expected:" << std::endl;
  TreePrinter::PrintTree(expectedTree);
  std::cout << "\033[0m" << std::endl;
  std::cout << "--------------------------" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8}, {30,36,21,36,35,26,15,-1,-1,-1,33,-1,-1,-1,8});
  testSolution({0,-1,1}, {1,-1,1});
}
