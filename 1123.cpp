//COMPILED USING: g++ 1123.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 1123

#include <iostream>
#include <ostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { // Ap 04, 2025
private:
std::pair<std::set<TreeNode*>, TreeNode*> dfs(TreeNode* node, std::set<TreeNode*> deepestLeaves) {
    if (!node) {
        return std::make_pair(std::set<TreeNode*>(), nullptr);
    }

    std::set<TreeNode*> currentSet;
    if (deepestLeaves.count(node) > 0) {
        currentSet.insert(node);
    }

    // Get results from left and right subtrees
    auto leftResult = dfs(node->left, deepestLeaves);
    auto rightResult = dfs(node->right, deepestLeaves);

    // Combine all sets of found leaves
    currentSet.insert(leftResult.first.begin(), leftResult.first.end());
    currentSet.insert(rightResult.first.begin(), rightResult.first.end());

    // If either subtree already found all leaves, return that result
    if (leftResult.first == deepestLeaves) {
        return leftResult;
    }

    if (rightResult.first == deepestLeaves) {
        return rightResult;
    }

    // If we found all deepest leaves at this node, this node is the LCA
    if (currentSet == deepestLeaves) {
        return std::make_pair(currentSet, node);
    }

    // Otherwise, just return what we've found so far
    return std::make_pair(currentSet, nullptr);
}

public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    // First find all deepest leaves using BFS
    std::queue<std::pair<TreeNode*, int>> bfs; //queue<pair<Node, Level>>
    bfs.push(std::make_pair(root, 0));
    std::set<TreeNode*> currLevelNodes = {root};
    int currLevel = 0;
    while(!bfs.empty()) {
      std::pair<TreeNode*, int> curr = bfs.front();
      bfs.pop();
      if(currLevel != curr.second) {
        currLevelNodes.clear();
        currLevel++;
      }
      currLevelNodes.insert(curr.first);
      if(curr.first->left) bfs.push(std::make_pair(curr.first->left, curr.second+1));
      if(curr.first->right) bfs.push(std::make_pair(curr.first->right, curr.second+1));
    }
    // for(TreeNode* i : currLevelNodes) {
    //   std::cout << i->val << std::endl;
    // }
    // std::cout << std::endl << currLevel << std::endl;

    // Now find lowest common ancestor of all nodes in currLevelNodes using DFS
    return dfs(root, currLevelNodes).second;
  }
};

void testSolution(std::vector<int> nums, std::vector<int> expected) {
  TreeNode* inputTree = TreeFactory::CreateTree(nums);

  std::cout << "Input:" << std::endl;
  TreePrinter::PrintTree(inputTree);
  std::cout << std::endl;

  TreeNode* expectedTree = TreeFactory::CreateTree(expected);
  Solution solution;
  TreeNode* res = solution.lcaDeepestLeaves(inputTree);

  bool correct = true;
  std::queue<TreeNode*> qRes;
  std::queue<TreeNode*> qExpected;

  // Handle edge case where both are null
  if (!res && !expectedTree) correct = true;
  if (!res || !expectedTree) correct = false;
  else {

    qRes.push(res);
    qExpected.push(expectedTree);

    while (!qRes.empty() && !qExpected.empty()) {
      TreeNode* currentRes = qRes.front();
      TreeNode* currentExpected = qExpected.front();

      // Check if either node is null
      if (!currentRes || !currentExpected) {
        correct = false;
        break;
      }
      
      if (currentRes->val != currentExpected->val) {
        correct = false;
        break;
      }

      // Process left children
      if (currentRes->left && currentExpected->left) {
        qRes.push(currentRes->left);
        qExpected.push(currentExpected->left);
      } else if (!currentRes->left && !currentExpected->left) {
        // Both null is fine
      } else {
        correct = false;
        break;
      }

      // Process right children
      if (currentRes->right && currentExpected->right) {
        qRes.push(currentRes->right);
        qExpected.push(currentExpected->right);
      } else if (!currentRes->right && !currentExpected->right) {
        // Both null is fine
      } else {
        correct = false;
        break;
      }

      qRes.pop();
      qExpected.pop();
    }

    // Check if both queues are empty
    if (!qRes.empty() || !qExpected.empty()) {
      correct = false;
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
  testSolution({3,5,1,6,2,0,8,-1,-1,7,4}, {2,7,4});
  testSolution({3,5,1,6,2,0,8,-1,-1,7,4,-1,-1,10,9}, {3,5,1,6,2,0,8,-1,-1,7,4,-1,-1,10,9});
  testSolution({1}, {1});
  testSolution({0,1,3,-1,2}, {2});
}
