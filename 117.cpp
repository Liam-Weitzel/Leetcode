#include <cstddef>
#include <queue>
#include <utility>

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

class Solution { // Sep 24, 2026
public:
  Node* connect(Node* root) {
    // Given a binary tree, populate each next pointer to point to its next right node.
    // If there is no next right node, the next pointer should be set to NULL.
    // Initially, all next pointers are set to NULL.
    //
    // Example 1:
    // Input: root = [1,2,3,4,5,null,7]
    // Output: [1,#,2,3,#,4,5,7,#]
    // Explanation: Given the above binary tree (Figure A),
    // your function should populate each next pointer to point to its next right node,
    // just like in Figure B. The serialized output is in level order as connected by the next pointers,
    // with '#' signifying the end of each level.
    //
    // Example 2:
    // Input: root = []
    // Output: []

    //if we do a bfs we always have the next as the next one that will be processed.
    //so effectively we can just keep a prev ptr and make sure that we never do that between levels

    if(!root) return root;

    std::queue<std::pair<Node*, int>> q;
    q.push(std::make_pair(root, 0));
    std::pair<Node*, int> prev = std::make_pair(nullptr, 0);

    while(!q.empty()) {
      Node* node = q.front().first;
      int level = q.front().second;

      if(node->left) q.push(std::make_pair(node->left, level+1));
      if(node->right) q.push(std::make_pair(node->right, level+1));

      if(prev.first && prev.second == level) prev.first->next = node;
      prev = q.front();
      q.pop();
    }

    return root;
  }
};
