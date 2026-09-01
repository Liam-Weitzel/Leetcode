#include <cstring>
#include <queue>
#include <string>
#include <vector>

class Solution { // Sep 01, 2026
public:
  int minMoves(std::vector<std::string>& classroom, int energy) {
    int n = classroom.size();
    int m = classroom[0].size();

    std::vector<std::vector<int>> litterIndex(n, std::vector<int>(m, -1));

    int litterCount = 0;
    int sx, sy;

    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        if (classroom[y][x] == 'L') {
          litterIndex[y][x] = litterCount++;
        } else if (classroom[y][x] == 'S') {
          sy = y;
          sx = x;
        }
      }
    }

    int fullMask = (1 << litterCount) - 1;

    // Maximum energy we've had when reaching (y, x, mask).
    // Anything <= this can be discarded.
    static int bestEnergy[20][20][1 << 10];
    memset(bestEnergy, -1, sizeof(bestEnergy));

    struct State {
      int i[5]; // x, y, mask, energy, steps
    };

    std::queue<State> q;
    q.push({{sx, sy, 0, energy, 0}});

    bestEnergy[sy][sx][0] = energy;

    int dir[5] = {0, 1, 0, -1, 0};

    while (!q.empty()) {
      State state = q.front();
      q.pop();

      int* i = state.i;

      int x = i[0];
      int y = i[1];
      int mask = i[2];
      int e = i[3];
      int steps = i[4];

      if (mask == fullMask)
        return steps;

      // Can't make another move.
      if (e == 0)
        continue;

      for (int d = 0; d < 4; ++d) {
        int nx = x + dir[d];
        int ny = y + dir[d + 1];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
          continue;

        if (classroom[ny][nx] == 'X')
          continue;

        int ne = e - 1;
        int nmask = mask;

        if (classroom[ny][nx] == 'R')
          ne = energy;

        if (classroom[ny][nx] == 'L')
          nmask |= 1 << litterIndex[ny][nx];

        // Same position + same collected litter, but we've
        // already been here with at least this much energy.
        if (ne <= bestEnergy[ny][nx][nmask])
          continue;

        bestEnergy[ny][nx][nmask] = ne;

        q.push({{nx, ny, nmask, ne, steps + 1}});
      }
    }

    return -1;
  }
};
