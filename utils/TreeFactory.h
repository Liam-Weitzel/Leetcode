#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "TreeNode.h"
#include <vector>

class TreeFactory {
public:
  static TreeNode* CreateTree(const std::vector<int>& input);
};

#endif // TREEFACTORY_H
