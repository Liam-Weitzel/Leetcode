//COMPILED USING: g++ 100.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 100

#include <iostream>
#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"
#include <memory>
#include <queue>
#include <vector>

class Solution { //Feb 26, 2024
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    std::queue<TreeNode*> bfs;
    bfs.push(p);
    bfs.push(q);

    while(!bfs.empty()) {
      if(!p && !q) return true;
      if(!p || !q) return false;
      TreeNode* pEl = bfs.front();
      bfs.pop();
      TreeNode* qEl = bfs.front();
      bfs.pop();

      if(pEl->val != qEl->val) return false;

      if(pEl->left && qEl->left) {
        bfs.push(pEl->left);
        bfs.push(qEl->left);
      }
      else if (!pEl->left && !qEl->left) {} 
      else return false;

      if(pEl->right && qEl->right) {
        bfs.push(pEl->right);
        bfs.push(qEl->right);
      }
      else if (!pEl->right && !qEl->right) {}
      else return false;
    }

    return true;
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> pVec = {1,2,3,4};
  std::vector<int> qVec = {1,2,3};

  TreeFactory factory;
  TreeNode* p = factory.createTree(pVec);
  TreeNode* q = factory.createTree(qVec);

  TreePrinter printer;
  printer.printTree(p);
  printer.printTree(q);

  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->isSameTree(p, q) << std::endl;
  
  return 0;
}
