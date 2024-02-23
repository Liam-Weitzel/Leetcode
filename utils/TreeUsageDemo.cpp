//COMPILED USING: g++ TreeUsageDemo.cpp TreeFactory.cpp TreePrinter.cpp -o TreeUsageDemo

#include <vector>
#include "TreeNode.h"
#include "TreeFactory.h"
#include "TreePrinter.h"

int main (int argc, char *argv[]) { 
  std::vector<int> input = {1, 2, 3, 4, 5, 6, -1, 8, 9, -1, 11, 12, 13, -1, 14, 15, -1, 16};

  TreeFactory factory;
  TreeNode* root = factory.createTree(input);

  TreePrinter printer;
  printer.printTree(root);

  return 0;
}
