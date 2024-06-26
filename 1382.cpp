//COMPILED USING: g++ 1382.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 1382

#include <iostream>
#include <queue>
#include <vector>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { // Jun 26, 2024
private:
  void dfsSort(TreeNode* root, std::vector<int>& sortedVals) {
    if(root->left) dfsSort(root->left, sortedVals);
    sortedVals.push_back(root->val);
    if(root->right) dfsSort(root->right, sortedVals);
  }

public:
  TreeNode* balanceBST(TreeNode* root) {
    //Generate a sorted array using DFS in O(n), generate balanced tree out of this by 'folding' around its middle...
    std::vector<int> sortedVals;
    dfsSort(root, sortedVals);

    int mid = (sortedVals.size()-1)/2;
    int left = mid;
    int right = mid;
    TreeNode* balanced = new TreeNode(sortedVals[mid], nullptr, nullptr);
    TreeNode* parentPtrLeft = balanced;
    TreeNode* parentPtrRight = balanced;
    while(left > 0 || right < sortedVals.size()-1) {
      if(left != 0) {
        left--;
        parentPtrLeft->left = new TreeNode(sortedVals[left], nullptr, nullptr);
        parentPtrLeft = parentPtrLeft->left;
      }
      if(right != sortedVals.size()-1) {
        right++;
        parentPtrRight->right = new TreeNode(sortedVals[right], nullptr, nullptr);
        parentPtrRight = parentPtrRight->right;
      }
    }
    //This binary search tree generation does not meet the criteria of the question...

    return balanced;
  }
};

void testSolution(std::vector<int> nums, std::vector<int> expected) {
  TreeNode* inputTree = TreeFactory::CreateTree(nums);

  std::cout << "Input:" << std::endl;
  TreePrinter::PrintTree(inputTree);
  std::cout << std::endl;

  TreeNode* expectedTree = TreeFactory::CreateTree(expected);
  Solution solution;
  TreeNode* res = solution.balanceBST(inputTree);

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
  testSolution({1,-1,2,-1,3,-1,4,-1,-1}, {2,1,3,-1,-1,-1,4});
  testSolution({2,1,3}, {2,1,3});
}
