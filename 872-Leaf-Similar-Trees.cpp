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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sequence1;
        vector<int> sequence2;

        dfs(root1, sequence1);
        dfs(root2, sequence2);

        return sequence1 == sequence2;
    }

    void dfs(TreeNode* node, vector<int> &sequence) {
        if(!node->left && !node->right) {
            sequence.push_back(node->val);
        } else {
            if (node->left) {
                dfs(node->left, sequence);
            }
            if (node->right) {
                dfs(node->right, sequence);
            }
        }
    }
};