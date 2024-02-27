//COMPILED USING: g++ 543.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 543

#include <algorithm>
#include <iostream>
#include <memory>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { //Feb 27, 2024
private:
  int longestPath = 0;
  TreeNode* root = nullptr;
public:
  int diameterOfBinaryTree(TreeNode* root) {
    if(!this->root) this->root = root;
    if(!root) return 0;

    int lpath = diameterOfBinaryTree(root->left);
    int rpath = diameterOfBinaryTree(root->right);
    longestPath = std::max(longestPath, lpath+rpath);

    if(root == this->root) return longestPath;
    return std::max(lpath, rpath)+1;
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> treeVec = {1,2,3,4,5,6,7,8,9};
  TreeFactory factory;
  TreeNode* root = factory.createTree(treeVec);
  TreePrinter printer;
  printer.printTree(root);

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->diameterOfBinaryTree(root) << std::endl;
  
  return 0;
}
