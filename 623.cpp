//COMPILED USING: g++ 623.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 623

#include <memory>
#include <queue>
#include <utility>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution { // Apr 16, 2024
public:
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth == 1) return new TreeNode(val, root, nullptr);

    std::queue<std::pair<TreeNode*, int>> q;
    q.push(std::make_pair(root, 1));

    while(!q.empty() && q.front().second <= depth) {
      TreeNode* node = q.front().first;
      int level = q.front().second;
      q.pop();

      if(node->left) q.push(std::make_pair(node->left, level+1));
      if(node->right) q.push(std::make_pair(node->right, level+1));

      if(level == depth-1) {
        node->left = new TreeNode(val, node->left, nullptr);
        node->right = new TreeNode(val, nullptr, node->right);
      }
    }

    return root;
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> treeVec = {3,9,20,-1,-1,15,7};
  TreeNode* root = TreeFactory::CreateTree(treeVec);
  TreePrinter::PrintTree(root);
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  root = res->addOneRow(root, 1, 2);
  TreePrinter::PrintTree(root);
  return 0;
}
