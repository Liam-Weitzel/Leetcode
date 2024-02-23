#ifndef TREEPRINTER_H
#define TREEPRINTER_H

#include "TreeNode.h"
#include <string>

class TreePrinter {
public:
  void printTree(const std::string& prefix, TreeNode* root, bool isLeft);
  void printTree(TreeNode* root);
};

#endif // TREEPRINTER_H
