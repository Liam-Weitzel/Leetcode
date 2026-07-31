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

class Solution { // Jul 31, 2026
private:
  bool dfs(TreeNode* node, int targetSum, int curSum) {
    curSum += node->val;
    bool found = false;
    if(node->left) found = found || dfs(node->left, targetSum, curSum);
    if(node->right && !found) found = found || dfs(node->right, targetSum, curSum);
    if(!node->left && !node->right && curSum == targetSum && !found) found = true;
    return found;
  }
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    return root ? dfs(root, targetSum, 0) : false;
  }
};
