#include <climits>
#include <iostream>
#include <ostream>
#include <vector>

class Solution {
public:
  int snakesAndLadders(std::vector<std::vector<int>>& board) {
    int n = board.size();
    std::vector<int> board1d(n * n);

    // Convert 2D to 1D with Boustrophedon pattern
    int idx = 0;
    for(int row = n - 1; row >= 0; row--) {
      if((n - 1 - row) % 2 == 0) {
        for(int col = 0; col < n; col++) {
          board1d[idx++] = board[row][col];
        }
      } else {
        for(int col = n - 1; col >= 0; col--) {
          board1d[idx++] = board[row][col];
        }
      }
    }

    // Switched to BFS instead of DFS to avoid stack overflow...
    std::vector<bool> visited(n * n, false);
    std::vector<int> queue{0};
    int moves = 0;

    while(!queue.empty()) {
      int size = queue.size();
      std::vector<int> next_queue;

      for(int i = 0; i < size; i++) {
        int curr = queue[i];
        if(curr == n * n - 1) return moves;

        for(int j = 1; j <= 6 && curr + j < n * n; j++) {
          int next = curr + j;
          if(board1d[next] != -1) {
            next = board1d[next] - 1;
          }
          if(!visited[next]) {
            visited[next] = true;
            next_queue.push_back(next);
          }
        }
      }
      queue = next_queue;
      moves++;
    }

    return -1;
  }
};

void testSolution(std::vector<std::vector<int>> board, int expected) {
  Solution res;
  int ans = res.snakesAndLadders(board);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Board: " << std::endl;
  for(std::vector<int> i : board) {
    for(int j : i) std::cout << j << ", ";
    std::cout << std::endl;
  }

  std::cout << "Ans: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}}, 4);
  testSolution({{-1,-1},{-1,3}}, 1);
}
