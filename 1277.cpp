#include <algorithm>
#include <unordered_map>
#include <vector>

/*
1,1,1,1,1
1,1,1,1,1
1,1,1,1,1
1,1,1,1,1
1,1,1,1,1

25+16+9+4+1

1,1,1,1
1,1,1,1
1,1,1,1
1,1,1,1

16+9+4+1

1,1,1
1,1,1
1,1,1

9+4+1

1,1
1,1

4 + 1

failing case:
[1,0,1,0,1],
[1,0,0,1,1],
[0,1,0,1,1],
[1,0,0,1,1]
*/

struct pairHash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};
class Solution { // Aug 20, 2025
public:
    int dfs(int r, int c, std::vector<std::vector<int>>& matrix, std::unordered_map<std::pair<int, int>, int, pairHash>& seen) {
        if (r >= matrix.size() || c >= matrix[0].size() || !matrix[r][c]) {
            return 0;
        }
        if (seen.count({r, c})) {
            return seen[{r, c}];
        }
        int largestSquare = 1 + std::min(
            {dfs(r + 1, c, matrix, seen),
            dfs(r + 1, c + 1, matrix, seen),
            dfs(r, c + 1, matrix, seen)}
        );
        seen[{r, c}] = largestSquare;
        return largestSquare;
    }

    int countSquares(std::vector<std::vector<int>>& matrix) {
        std::unordered_map<std::pair<int, int>, int, pairHash> memo;
        int countSquares = 0;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                countSquares += dfs(row, col, matrix, memo);
            }
        }
        return countSquares;
    }
};
