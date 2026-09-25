#include <cstddef>

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution { // Sep 25, 2026
public:
  Node* connect(Node* root) {
    //in order to use constant extra space we need to use the next part of the node as a queue for bfs
    //we need to temporarily set next of the last element of a level to the first element of the next level in order to traverse it cleanly. then sever later.
    //the easiest way to do this is by counting current level and whenever we see the first of a new level, storing it. CONSTANT SPACE
    Node* cur = root;
    Node* nextLevel = nullptr;

    while(cur) {
      if(cur->left && cur->right)
        cur->left->next = cur->right;
      if(cur->right && cur->next)
        cur->right->next = cur->next->left;

      if(!nextLevel) nextLevel = cur->left;

      if(cur->next) cur = cur->next;
      else {
        cur = nextLevel;
        nextLevel = nullptr;
      }
    }

    return root;
  }
};
