#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, prev = 0;
        for(int i = 0; i < nums.size(); i++) {
            int temp = max(prev+nums[i], cur);
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};