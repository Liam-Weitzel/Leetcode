//COMPILED USING: g++ 513.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 513

#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { // Feb 28, 2024
public:
  int findBottomLeftValue(TreeNode* root) {
    std::queue<TreeNode*> q;
    TreeNode* currNode = root;
    q.push(currNode);

    while (!q.empty()) {
      currNode = q.front();
      q.pop();
      if(currNode->right) q.push(currNode->right); 
      if(currNode->left) q.push(currNode->left);
    }

    return currNode->val;
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> treeVec = {1,2,3,4,5,6,7,8,9};
  TreeFactory factory;
  TreeNode* root = factory.createTree(treeVec);
  TreePrinter printer;
  printer.printTree(root);

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->findBottomLeftValue(root) << std::endl;
  
  return 0;
}
