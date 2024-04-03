#include <algorithm>
#include <memory>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>

class Solution { // Apr 03, 2024
private:
  std::string dfs(std::vector<std::vector<char>>& board, std::string& word, int row, int col, int depth, std::set<std::pair<int, int>> visited) {
    visited.insert(std::make_pair(row, col));
    depth++;

    std::string res = "";
    if(row-1 >= 0 && depth < word.size() && word[depth] == board[row-1][col] && visited.find(std::make_pair(row-1, col)) == visited.end()) {
       res = dfs(board, word, row-1, col, depth, visited);
       if(res == word.substr(depth)) return board[row][col] + res;
    }
    if(row+1 < board.size() && depth < word.size() && word[depth] == board[row+1][col] && visited.find(std::make_pair(row+1, col)) == visited.end()) {
      res = dfs(board, word, row+1, col, depth, visited);
      if(res == word.substr(depth)) return board[row][col] + res;
    }
    if(col-1 >= 0 && depth < word.size() && word[depth] == board[row][col-1] && visited.find(std::make_pair(row, col-1)) == visited.end()) {
      res = dfs(board, word, row, col-1, depth, visited);
      if(res == word.substr(depth)) return board[row][col] + res;
    }
    if(col+1 < board[0].size() && depth < word.size() && word[depth] == board[row][col+1] && visited.find(std::make_pair(row, col+1)) == visited.end()) {
      res = dfs(board, word, row, col+1, depth, visited);
      if(res == word.substr(depth)) return board[row][col] + res;
    }

    return std::string() + board[row][col];
  }

public:
  bool exist(std::vector<std::vector<char>>& board, std::string& word) {
    if(std::count(word.begin(), word.end(), word[0]) > std::count(word.begin(), word.end(), word[word.size()-1])) {
      std::reverse(word.begin(), word.end());  
    }

    std::map<char, int> freqMap;
    std::vector<std::pair<int, int>> starts;
    for(int row = 0; row < board.size(); row++) {
      for(int col = 0; col < board[row].size(); col++) {
        freqMap[board[row][col]]++;
        if(board[row][col] == word[0]) starts.push_back(std::make_pair(row, col));
      }
    }

    for(char i : word) freqMap[i]--;
    for(std::pair<char, int> i : freqMap) if(i.second < 0) return false;

    for(std::pair<int, int> start : starts) {
      if(dfs(board, word, start.first, start.second, 0, std::set<std::pair<int, int>>()) == word) return true;
    }

    return false;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  std::string word = "ABCCED";
  std::cout << res->exist(board, word) << std::endl;
  return 0;
}
