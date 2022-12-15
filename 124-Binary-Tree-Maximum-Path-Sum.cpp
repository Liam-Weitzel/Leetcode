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
 **/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        dfs(root, maxsum);
        return maxsum;
    }

    int dfs(TreeNode* node, int& maxsum) {
        int sumleft = 0;
        int sumright = 0;
        
        if (node->left) {
            sumleft = dfs(node->left, maxsum);
        }
        if (node->right) {
            sumright = dfs(node->right, maxsum);
        }

        int maxLvsR = max(sumleft + node->val, sumright + node->val);
        int maxLvsRvsLR = max(maxLvsR, (node->val + sumleft + sumright));
        int maxLvsRvsLRvsNode = max(maxLvsRvsLR, node->val);

        if(maxsum < maxLvsRvsLRvsNode) maxsum = maxLvsRvsLRvsNode;
        
        return max(max(sumleft + node->val, sumright + node->val), node->val);
    }
};