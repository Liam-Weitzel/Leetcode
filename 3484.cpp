#include <cassert>
#include <vector>
#include <string>

class Spreadsheet { // Sep 19, 2025
private:
  std::vector<std::vector<int>> spreadsheet;

   int* cellToCell(std::string cell) {
    int row = atoi(cell.substr(1).c_str());
    int col = cell[0] - 'A';
    return &spreadsheet[row][col];
  }

public:
  Spreadsheet(int rows) {
    spreadsheet = std::vector<std::vector<int>>(rows+1, std::vector<int>(26, 0));
  }

  void setCell(std::string cell, int value) {
    int* c = cellToCell(cell);
    *c = value;
  }

  void resetCell(std::string cell) {
    int* c = cellToCell(cell);
    *c = 0;
  }

  int getValue(std::string formula) {
    int plusPos = formula.find('+');

    std::string cell1 = formula.substr(1,plusPos-1);
    std::string cell2 = formula.substr(plusPos+1);

    int c1 = 0;
    int c2 = 0;

    if(*cell1.begin() >= 'A') {
      c1 = *cellToCell(cell1);
    } else {
      c1 = atoi(cell1.c_str());
    }

    if(*cell2.begin() >= 'A') {
      c2 = *cellToCell(cell2);
    } else {
      c2 = atoi(cell2.c_str());
    }

    return c1 + c2;
  }
};
