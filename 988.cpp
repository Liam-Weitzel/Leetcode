//COMPILED USING: g++ 988.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 988

#include <algorithm>
#include <iostream>
#include <memory>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { // Apr 17, 2024
public:
  std::string dfs(TreeNode* node, TreeNode* parent) {
    std::string left = "";
    std::string right = "";
    
    if(node->left) {
      left = dfs(node->left, node);
    }
    if(node->right) {
      right = dfs(node->right, node);
    }

    std::string res = "";
    if(left != "" && right != "") {
      std::string TempLeft = left;
      std::string TempRight = right;
      TempLeft += 'a' + node->val;
      TempRight += 'a' + node->val;
      TempRight += 'a' + parent->val;
      TempLeft += 'a' + parent->val;
      res = std::lexicographical_compare(TempLeft.begin(), TempLeft.end(), TempRight.begin(), TempRight.end()) ? left : right;
    } else if (left != "") {
      res = left;
    } else if (right != "") {
      res = right;
    }

    res += 'a' + node->val;

    return res;
  }

  std::string smallestFromLeaf(TreeNode* root) {
    return dfs(root, root);
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> treeVec = {0,1,2,3,4,3,4};
  TreeNode* root = TreeFactory::CreateTree(treeVec);
  TreePrinter::PrintTree(root);

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->smallestFromLeaf(root) << std::endl;

  return 0;
}
