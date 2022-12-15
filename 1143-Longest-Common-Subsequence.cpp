using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
        vector<vector<int>> matrix(a.length()+1, vector<int>(b.length()+1));

        for(int i = a.length()-1; i >= 0; i--) {
            for(int j = b.length()-1; j >= 0; j--) {
                if(a[i] == b[j]) {
                    matrix[i][j] = matrix[i+1][j+1] + 1;
                } else {
                    matrix[i][j] = max(matrix[i][j+1], matrix[i+1][j]);
                }
            }
        }

        return matrix[0][0];
    }
};