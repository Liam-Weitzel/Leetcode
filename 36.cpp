#include <set>
#include <vector>

class Solution { // Aug 30, 2025
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {

    for(int y = 0; y < board.size(); y++) {
      std::set<char> seen;
      for(int x = 0; x < board[0].size(); x++) {
        char curr = board[y][x];
        if(curr != '.') {
          if(seen.contains(curr)) return false;
          seen.insert(curr);
        }
      }
    }

    for(int x = 0; x < board[0].size(); x++) {
      std::set<char> seen;
      for(int y = 0; y < board.size(); y++) {
        char curr = board[y][x];
        if(curr != '.') {
          if(seen.contains(curr)) return false;
          seen.insert(curr);
        }
      }
    }

    std::vector<int> dx = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    std::vector<int> dy = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    for(int y = 1; y < board.size(); y+=3) {
      for(int x = 1; x < board.size(); x+=3) {
        std::set<char> seen;
        for(int i = 0; i < dx.size(); i++) {
          int ddx = x + dx[i];
          int ddy = y + dy[i];
          char curr = board[ddy][ddx];
          if(curr != '.') {
            if(seen.contains(curr)) return false;
            seen.insert(curr);
          }
        }
      }
    }

    return true;
  }
};
