#include <string>
#include <vector>

class Solution { // Jul 21, 2026
public:
  std::vector<std::string> cellsInRange(std::string s) {
    int cells[] = {s[0] - 'A', s[1] - '0', s[3] - 'A', s[4] - '0'};

    std::vector<std::string> res;
    for(int col = cells[0]; col <= cells[2]; col++) {
      char curCol = col + 'A';
      for(int row = cells[1]; row <= cells[3]; row++) {
        char curRow = row + '0';
        std::string curCell;
        curCell += (curCol);
        curCell += (curRow);
        res.push_back(curCell);
      }
    }
    return res;
  }
};
