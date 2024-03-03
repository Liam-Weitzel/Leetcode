//COMPILED USING: g++ 1609.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 1609

#include <iostream>
#include <memory>
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"
#include <queue>
#include <utility>

class Solution { // Feb 29, 2024
public:
  bool isEvenOddTree(TreeNode* root) {

    std::queue<std::pair<TreeNode*, int>> q;
    q.push(std::make_pair(root, 0));
    std::pair<TreeNode*, int> lastNode = std::make_pair(root, -1);

    while(!q.empty()) {
      std::pair<TreeNode*, int> curr = q.front();
      bool isLayerEven = (curr.second%2==0);

      if(curr.second == lastNode.second) {
        if(isLayerEven && lastNode.first->val >= curr.first->val) return false;
        if(!isLayerEven && lastNode.first->val <= curr.first->val) return false;
      }

      if(isLayerEven && curr.first->val%2==0) return false;
      if(!isLayerEven && curr.first->val%2!=0) return false;

      if(curr.first->left) q.push(std::make_pair(curr.first->left, curr.second+1));
      if(curr.first->right) q.push(std::make_pair(curr.first->right, curr.second+1));
      lastNode = curr;
      q.pop();
    }

    return true;
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> treeVec = {1,2,3,4,5,6,7,8,9};
  TreeNode* root = TreeFactory::CreateTree(treeVec);
  TreePrinter::PrintTree(root);

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->isEvenOddTree(root) << std::endl;
  
  return 0;

}
