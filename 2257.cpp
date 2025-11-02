#include <vector>

class Solution { // Nov 02, 2025
private:
    enum tileState {
        guard,
        free,
        wall,
        seen
    };

public:
    int countUnguarded(
        int m,
        int n,
        std::vector<std::vector<int>>& guards,
        std::vector<std::vector<int>>& walls
    ) {
        std::vector<std::vector<tileState>> matrix(m, std::vector<tileState>(n, free));
        int marked = 0;

        for (auto& w : walls) {
            matrix[w[0]][w[1]] = wall;
            marked++;
        }

        for (auto& g : guards) {
            matrix[g[0]][g[1]] = guard;
            marked++;
        }

        for (auto& g : guards) {
            int r = g[0], c = g[1];
            // up
            for (int i = r - 1; i >= 0; --i) {
                if (matrix[i][c] == wall || matrix[i][c] == guard) break;
                if (matrix[i][c] == free) { matrix[i][c] = seen; marked++; }
            }
            // down
            for (int i = r + 1; i < m; ++i) {
                if (matrix[i][c] == wall || matrix[i][c] == guard) break;
                if (matrix[i][c] == free) { matrix[i][c] = seen; marked++; }
            }
            // left
            for (int j = c - 1; j >= 0; --j) {
                if (matrix[r][j] == wall || matrix[r][j] == guard) break;
                if (matrix[r][j] == free) { matrix[r][j] = seen; marked++; }
            }
            // right
            for (int j = c + 1; j < n; ++j) {
                if (matrix[r][j] == wall || matrix[r][j] == guard) break;
                if (matrix[r][j] == free) { matrix[r][j] = seen; marked++; }
            }
        }

        return m * n - marked;
    }
};
