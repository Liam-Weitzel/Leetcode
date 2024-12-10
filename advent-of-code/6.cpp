#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream file("6.txt");
  std::string line;

  std::vector<std::vector<char>> map;

  while (std::getline(file, line)) {
    map.push_back(std::vector<char>());
    for(char i : line) map.back().push_back(i);
  }

  file.close();

  std::pair<int, int> start(-1, -1);
  for(int row = 0; row < map.size(); row++) {
    for(int col = 0; col < map[0].size(); col++) {
      if(map[row][col] == '^') {
        start = std::make_pair(row, col);
        break;
      }
    }
    if(start != std::make_pair(-1, -1)) break;
  }

  std::pair<int, int> curr_pos = start;
  char direction = 'U';
  while(curr_pos.first < map.size() && curr_pos.first >= 0 && curr_pos.second < map[0].size() && curr_pos.second >= 0) {
    map[curr_pos.first][curr_pos.second] = 'X';
    switch (direction) {
      case 'U':
        if(curr_pos.first == 0) curr_pos.first--;
        else if(map[curr_pos.first-1][curr_pos.second] == '#') {
          direction = 'R';
        } else curr_pos.first--;
        break;
      case 'D':
        if(curr_pos.first == map.size()-1) curr_pos.first++;
        else if(map[curr_pos.first+1][curr_pos.second] == '#') {
          direction = 'L';
        } else curr_pos.first++;
        break;
      case 'R':
        if(curr_pos.second == map[0].size()-1) curr_pos.second++;
        else if(map[curr_pos.first][curr_pos.second+1] == '#') {
          direction = 'D';
        } else curr_pos.second++;
        break;
      case 'L':
        if(curr_pos.second == 0) curr_pos.second--;
        else if(map[curr_pos.first][curr_pos.second-1] == '#') {
          direction = 'U';
        } else curr_pos.second--;
        break;
    }
  }

  int res = 0;
  for(std::vector<char> row : map) {
    for(char col : row) {
      if(col == 'X') res++;
      std::cout << col;
    }
    std::cout << std::endl;
  }

  std::cout << "part one: " << res << std::endl;

  return 0;
}
