#include <queue>
#include <utility>
#include <vector>
#include "utils/TreeNode.h"

class Solution { // Nov 20, 2026
public:
  std::vector<double> averageOfLevels(TreeNode* root) {
    std::queue<std::pair<TreeNode*, int>> q; // first is node, second is level
    std::vector<std::pair<long long,int>> sum_count; // index is the level, first is sum, second is count
    q.push(std::make_pair(root, 0));

    while (!q.empty()) {
      TreeNode* node = q.front().first;
      int level = q.front().second;
      q.pop();

      if(level >= sum_count.size()) sum_count.push_back(std::make_pair(0, 0));
      sum_count[level].second++;
      sum_count[level].first += node->val;

      if(node->left) q.push(std::make_pair(node->left, level+1));
      if(node->right) q.push(std::make_pair(node->right, level+1));
    }

    std::vector<double> avg(sum_count.size(), 0);

    for(int i = 0; i < sum_count.size(); i++)
      avg[i] = (double) sum_count[i].first / sum_count[i].second;

    return avg;
  }
};
