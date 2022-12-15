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
 
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        //use dfs to record the max and min per parent to child relationship -> then find the max abs sum of these (1 for each node)
        int highest = 0;
        dfs(root, root->val, root->val, highest); 
        return highest;  
    }

    void dfs(TreeNode* node, int max, int min, int& highest) {
        if(abs(node->val-max) > highest) {
            highest = abs(node->val-max);
        }
        if(abs(node->val-min) > highest) {
            highest = abs(node->val-min);
        }
        if(node->val > max) {
            max = node->val;
        }
        if(node->val < min) {
            min = node->val;
        }

        if(node->left) {
            dfs(node->left, max, min, highest);
        }
        if(node->right) {
            dfs(node->right, max, min, highest);
        }
    }
};