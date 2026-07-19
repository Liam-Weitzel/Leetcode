#include <algorithm>
#include <numeric>
#include <vector>

class Solution { // Jul 19, 2026
public:
    long long maximumTotalSum(std::vector<int>& maximumHeight) {
        //2, 3, 4, 3
        //4, 3, 3, 2
        //4, 3, 2, 1

        //2, 3, 4, 5, 6, 1, 2, 3, 4, 5
        //6, 5, 5, 4, 4, 3, 3, 2, 2, 1
        //6, 5, 4, 3, 2, 1, 0, 0, 0, 0
        
        //20, 16, 13, 2, 2
        //20, 16, 13, 2, 1

        //sort desc
        //set of assigned heights (always as high as possible)
        //this is a very bad solution ime complexity wise, after lets change it to use a free linked list
        //looked at the hint as this was too hard
        //After sorting, it can be seen that the maximum height that we can assign to the ith element is min(maximumHeight[i], maximumHeight[i - 1] - 1).
        
        std::sort(maximumHeight.begin(), maximumHeight.end(), std::greater<int>());
        for(int i = 1; i < maximumHeight.size(); i++) {
            maximumHeight[i] = std::min(maximumHeight[i], maximumHeight[i - 1] - 1);
        }

        if(maximumHeight.back() <= 0) return -1;
        return std::accumulate(maximumHeight.begin(), maximumHeight.end(), 0LL);
    }
};
