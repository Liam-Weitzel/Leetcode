#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxRemoval(std::vector<int> nums, std::vector<std::vector<int>> queries) {
    std::vector<int> diff(nums.size()+1);
    for(std::vector<int> i : queries) {
      diff[i[0]]--;
      diff[i[1]+1]++;
    }

    int sum = 0;
    for(int i = 0; i < diff.size(); i++) {
      sum+=diff[i];
      diff[i]=sum;
    }

    for(int i = 0; i < nums.size(); i++) nums[i]+=diff[i];

    if(*std::max(nums.begin(), nums.end()) > 0) return -1;

    std::sort(queries.begin(), queries.end(), 
        [](const auto& a, const auto& b) {
            return (a[1] - a[0]) < (b[1] - b[0]);
        });

    int count = 0;
    for(std::vector<int> q : queries) {
      if(*std::max(nums.begin()+q[0], nums.begin()+q[1]) > 0) continue;
      for(int i = q[0]; i <= q[1]; i++) nums[i]++;
      count++;
    }

    return count;
  }
};

void testSolution(std::vector<int> nums, std::vector<std::vector<int>> queries, int expected) {
  Solution res;
  int ans = res.maxRemoval(nums, queries);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Nums: " << std::endl;
  for(int i : nums) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Queries: " << std::endl;
  for(std::vector<int> i : queries) std::cout << "[ " << i[0] << " - " << i[1] << " ], ";
  std::cout << std::endl;

  std::cout << "Ans: " << ans << std::endl;

  std::cout << "Epected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({2,0,2}, {{0,2},{0,2},{1,1}}, 1);
  testSolution({1,1,1,1}, {{1,3},{0,2},{1,3},{1,2}}, 2);
  testSolution({1,2,3,4}, {{0,3}}, -1);
}
