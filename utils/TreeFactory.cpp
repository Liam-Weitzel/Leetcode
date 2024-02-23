#include "TreeFactory.h"
#include <queue>


TreeNode* TreeFactory::createTree(const std::vector<int>& input) {
  if (input.empty() || input[0] == -1) return nullptr;

  TreeNode* root = new TreeNode(input[0]);
  std::queue<TreeNode**> q;
  q.push(&(root->left));
  q.push(&(root->right));

  for (int i = 1; i < input.size(); ++i) {
    TreeNode** curr = q.front();
    q.pop();
    if (input[i] != -1) {
      *curr = new TreeNode(input[i]);
      q.push(&((*curr)->left));
      q.push(&((*curr)->right));
    }
  }

  return root;
};
