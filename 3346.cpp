#include <algorithm>
#include <climits>
#include <vector>

class Solution { // Oct 21, 2025
public:
    int maxFrequency(std::vector<int>& nums, int k, int numOperations) {
        int maxVal = *std::max_element(nums.begin(), nums.end()) + k + 2;
        int* count = new int[maxVal]();

        for (int v : nums)
            count[v]++;

        for (int i = 1; i < maxVal; i++)
            count[i] += count[i - 1];

        int res = 0;
        for (int i = 0; i < maxVal; i++) {
            int left = std::max(0, i - k);
            int right = std::min(maxVal - 1, i + k);
            int total = count[right] - (left ? count[left - 1] : 0);
            int freq = count[i] - (i ? count[i - 1] : 0);
            res = std::max(res, freq + std::min(numOperations, total - freq));
        }

        return res;
    }
};
