//COMPILED USING: g++ TreeUsageDemo.cpp TreeFactory.cpp TreePrinter.cpp -o TreeUsageDemo

#include <cstdlib>
#include <vector>
#include "TreeNode.h"
#include "TreeFactory.h"
#include "TreePrinter.h"

int main (int argc, char *argv[]) { 
  std::vector<int> input = {1, 2, 3, 4, 5, 6, -1, 8, 9, -1, 11, 12, 13, -1, 14, 15, -1, 16};
  TreeNode* root = TreeFactory::CreateTree(input);
  TreePrinter::PrintTree(root);
  free(root);
  return 0;
}
