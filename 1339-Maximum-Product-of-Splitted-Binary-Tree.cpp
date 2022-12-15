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
    int maxProduct(TreeNode* root) {
        long long sum = dfsFindSum(root, 0);

        //dfs, when reaching leaf, subtract from sum and compare
        pair<long long, long long> res = dfsFindMaxProd(root, 0, sum, 0);

        return res.first%(int)(1e9+7);

    }

    long long dfsFindSum(TreeNode* node, long long sum) {
        long long sumleft = 0;
        long long sumright = 0;

        if (node->left) {
            sumright = dfsFindSum(node->left, sum);
        }
        if (node->right) {
            sumleft = dfsFindSum(node->right, sum);
        }
        sum = node->val + sumright + sumleft;

        return sum;
    }

    pair<long long, long long> dfsFindMaxProd(TreeNode* node, long long highest, long long sum, long long runningsum) {
        long long highestleft = 0;
        long long highestright = 0;
        long long runningsumleft = 0;
        long long runningsumright = 0;
        
        if(node->left) {
            pair<long long, long long> leftres = dfsFindMaxProd(node->left, highest, sum, runningsum);
            highestleft = leftres.first;
            runningsumleft = leftres.second;
        }
        if(node->right) {
            pair<long long, long long> rightres = dfsFindMaxProd(node->right, highest, sum, runningsum);
            highestright = rightres.first;
            runningsumright = rightres.second;        
        }

        highest = max(highestleft, highestright);
        runningsum = runningsum + node->val + runningsumright + runningsumleft;

        if((sum-runningsum) * runningsum > highest) {
            highest = (sum-runningsum) * runningsum;
        }
        cout << sum << " | " << highest << " | " << runningsum << endl;

        return make_pair(highest, runningsum);
    }
};