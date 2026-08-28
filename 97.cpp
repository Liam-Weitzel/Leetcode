#include <array>
#include <map>
#include <string>

class Solution { // Aug 28, 2026
private:
  bool dfs(std::map<std::array<int, 3>, bool>& memo, std::string& s1, std::string& s2, std::string& s3, int i1, int i2, int i3) {
    if(memo.contains({i1, i2, i3})) return memo[{i1, i2, i3}];
    if(i3 == s3.size()) {
      memo[{i1, i2, i3}] = true;
      return true;
    }

    bool res = false;
    if(i1 < s1.size() && s1[i1] == s3[i3]) res += dfs(memo, s1, s2, s3, i1+1, i2, i3+1);
    if(res == true) {
      memo[{i1, i2, i3}] = true;
      return true; // cheap early return
    }
    if(i2 < s2.size() && s2[i2] == s3[i3]) res += dfs(memo, s1, s2, s3, i1, i2+1, i3+1);

    memo[{i1, i2, i3}] = res;
    return res;
  }

public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    //this is not just a simple two pointer approach as when both work, depending on which one we pick, the answer might differ
    //so this leans DFS instead of two pointer + greedy picking
    //can we memoize this? not sure, would have to draw out the tree for an example to see if it saves time
    //TLE so lets try memoization + early return -> would be cleaner to do it with a DP table but whatever...
    std::map<std::array<int, 3>, bool> memo;
    if(!s3.size() && !s1.size() && !s2.size()) return true;
    if(s3.size() != s1.size() + s2.size()) return false;
    return dfs(memo, s1, s2, s3, 0, 0, 0);
  }
};
