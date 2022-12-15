#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        map<int, int> memoization;

        return dfs(0, n, memoization);
    }

    int dfs(int curr, int n, map<int, int>& memoization) {
        if (memoization.find(curr) != memoization.end()) {
            return memoization[curr];
        } else if (curr == n) {
            return 1;
        } else if (curr > n) {
            return 0;
        }
        int res = dfs(curr+1, n, memoization) + dfs(curr+2, n, memoization);
        memoization[curr] = res;
        return res;
    }
};