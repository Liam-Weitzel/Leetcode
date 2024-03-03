#include <iostream>
#include "TreePrinter.h"

void TreePrinter::PrintTree(const std::string& prefix, TreeNode* node, bool isLeft) {
  if( node != nullptr ) {
    std::cout << prefix;

    std::cout << (isLeft ? "├──" : "└──" );

    // print the value of the node
    std::cout << node->val << std::endl;

    // enter the next tree level - left and right branch
    PrintTree( prefix + (isLeft ? "│   " : "    "), node->left, node->right);
    PrintTree( prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}

void TreePrinter::PrintTree(TreeNode* root) {
  PrintTree("", root, false);
}
