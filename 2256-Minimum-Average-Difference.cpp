#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int lowest = INT_MAX;
        int lowest_index = 0;
        long long int sum_of_before = 0;
        long long int sum_of_after = accumulate(nums.begin(), nums.end(), 0LL);;
        int n = nums.size();
        int avg_diff = 0;
        int i_before = 0;
        int i_after = 0;

        for(int i = 0; i < n; i++) {
            sum_of_before = sum_of_before + nums[i];
            sum_of_after = sum_of_after - nums[i];
            i_before = i + 1;
            i_after = n-(i+1);
            if (i_before == 0){
                avg_diff = 0 - (sum_of_after / i_after);
            } else if (i_after == 0) {
                avg_diff = (sum_of_before / i_before) - 0;
            } else {
                avg_diff = (sum_of_before / i_before) - (sum_of_after / i_after);
            }
            avg_diff = abs(avg_diff);
            if (avg_diff < lowest) {
                lowest = avg_diff;
                lowest_index = i;
            }
        }

        return lowest_index;

    }
};