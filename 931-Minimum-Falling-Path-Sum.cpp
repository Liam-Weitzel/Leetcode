#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> minsum(matrix.size(), vector<int>(matrix[0].size()));
        int minsumint = INT_MAX;

        for(int i = minsum.size()-1; i >= 0; i--) {
            for(int j = minsum[i].size()-1; j >= 0; j--) {
                int d = INT_MAX;
                int dl = INT_MAX;
                int dr = INT_MAX;
                if (i != minsum.size()-1) {
                    //can go down
                    d = minsum[i+1][j];
                }
                if (i != minsum.size()-1 && j != 0) {
                    //can go down & left
                    dl = minsum[i+1][j-1];
                }
                if (i != minsum.size()-1 && j != minsum[i].size()-1) {
                    //can go down & right
                    dr = minsum[i+1][j+1];
                }

                if(d == INT_MAX && dl == INT_MAX && dr == INT_MAX) {
                    minsum[i][j] = matrix[i][j];
                } else {
                    minsum[i][j] = min(d, min(dl, dr)) + matrix[i][j];
                }

                if (i == 0 && minsum[i][j] < minsumint) {
                    minsumint = minsum[i][j];
                }
                
                cout << matrix[i][j] << endl;
            }
        }

        return minsumint;        
    }

    /*
    //first try:
    //time:O(n), space:O(n), recursion tree with memoization      

    int minFallingPathSum(vector<vector<int>>& matrix) {
        map<pair<int, int>, int> memoization;

        vector<int> res;
        for(int i = 0; i < matrix.size(); i++) {
            res.push_back(recursive(matrix, make_pair(0, i), memoization));
        }

        int result = *min_element(res.begin(), res.end());

        return result;        
    }

    int recursive(vector<vector<int>>& matrix, pair<int, int> coords, map<pair<int, int>, int>& memoization) {
        
        if(memoization.find(coords) != memoization.end()) {
            //if node already visited
            return memoization[coords];
        }
        
        int bl = INT_MAX;
        int b = INT_MAX;
        int br = INT_MAX;
        
        if (coords.first == matrix.size()-1) {
            //if already at bottom
            return matrix[coords.first][coords.second];
        }

        if(coords.first != matrix.size()-1 && coords.second != 0) {
            //go bottom left
            bl = recursive(matrix, make_pair(coords.first+1, coords.second-1), memoization);
        }
        if(coords.first != matrix.size()-1) {
            //go bottom
            b = recursive(matrix, make_pair(coords.first+1, coords.second), memoization);
        }
        if(coords.first != matrix.size()-1 && coords.second != matrix.size()-1) {
            //go bottom right
            br = recursive(matrix, make_pair(coords.first+1, coords.second+1), memoization);
        }

        memoization[coords] = matrix[coords.first][coords.second] + min(bl, min(b, br));
        return memoization[coords];
    }
    */
};