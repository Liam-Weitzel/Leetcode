#include <iostream>
#include "TreeNode.h"
#include "TreePrinter.h"

void TreePrinter::printTree(const std::string& prefix, TreeNode* node, bool isLeft) {
  if( node != nullptr ) {
    std::cout << prefix;

    std::cout << (isLeft ? "├──" : "└──" );

    // print the value of the node
    std::cout << node->val << std::endl;

    // enter the next tree level - left and right branch
    printTree( prefix + (isLeft ? "│   " : "    "), node->left, node->right);
    printTree( prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}

void TreePrinter::printTree(TreeNode* root) {
  printTree("", root, false);    
}
