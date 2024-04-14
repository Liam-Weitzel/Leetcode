//COMPILED USING: g++ 404.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 404

#include <iostream>
#include <memory>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { // Apr 14, 2024
private:
  int dfs(TreeNode* node, bool isLeft) {
    if(!node->left && !node->right && isLeft) return node->val;

    int res = 0;
    if(node->left) res += dfs(node->left, true);
    if(node->right) res += dfs(node->right, false);

    return res;
  }
public:
  int sumOfLeftLeaves(TreeNode* root) {
    return dfs(root, false);
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> treeVec = {3,9,20,-1,-1,15,7};
  TreeNode* root = TreeFactory::CreateTree(treeVec);
  TreePrinter::PrintTree(root);

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->sumOfLeftLeaves(root) << std::endl;

  return 0;
}
