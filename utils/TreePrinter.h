#ifndef TREEPRINTER_H
#define TREEPRINTER_H

#include "TreeNode.h"
#include <string>

class TreePrinter {
public:
  static void PrintTree(const std::string& prefix, TreeNode* root, bool isLeft);
  static void PrintTree(TreeNode* root);
};

#endif // TREEPRINTER_H
