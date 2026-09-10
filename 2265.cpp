/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "utils/TreeNode.h"
#include <utility>

class Solution { // Sep 10, 2026
private:
  std::pair<int, int> dfs(TreeNode* node, int& res) {
    std::pair<int, int> count = std::make_pair(1, node->val);

    if(node->right) {
      std::pair<int, int> right = dfs(node->right, res);
      count.first += right.first;
      count.second += right.second;
    }

    if(node->left) {
      std::pair<int, int> left = dfs(node->left, res);
      count.first += left.first;
      count.second += left.second;
    }

    if(count.second/count.first == node->val) res++;

    return count;
  }
public:
  int averageOfSubtree(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res;
  }
};
