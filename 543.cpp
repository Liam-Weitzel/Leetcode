//COMPILED USING: g++ 543.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 543

#include <algorithm>
#include <iostream>
#include <memory>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"

class Solution2 { // Feb 27, 2024
private:
  int longestPath = 0;
  TreeNode* root = nullptr;
public:
  int diameterOfBinaryTree(TreeNode* root) {
    if(!this->root) this->root = root;
    if(!root) return 0;

    int lpath = diameterOfBinaryTree(root->left);
    int rpath = diameterOfBinaryTree(root->right);
    longestPath = std::max(longestPath, lpath+rpath);

    if(root == this->root) return longestPath;
    return std::max(lpath, rpath)+1;
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> treeVec = {1,2,3,4,5,6,7,8,9};
  TreeNode* root = TreeFactory::CreateTree(treeVec);
  TreePrinter::PrintTree(root);

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->diameterOfBinaryTree(root) << std::endl;
  
  return 0;
}

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
class Solution { // Aug 13, 2026
private:
    int dfs(TreeNode* node, int& max) {
    int left = 0;
    if(node->left) left = dfs(node->left, max);
    int right = 0;
    if(node->right) right = dfs(node->right, max);

    max = std::max(max, left+right);

    return std::max(left, right)+1; 
  }
public:
  int diameterOfBinaryTree(TreeNode* root) {
    //precomputation: We create a map containing distances from root per node
    //Can we use that to infer distances between each other on a second pass? 
    //No we just have to do it via dfs while keeping max dist...
    int max = 0;

    dfs(root, max);

    return max;
  }
};
