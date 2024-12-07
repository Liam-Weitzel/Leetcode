#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

bool isValidSequence(const std::vector<int>& nums) {
  if (nums.size() < 2) return true;

  int prev = nums[0];
  short order = 0;

  for (size_t i = 1; i < nums.size(); i++) {
    int diff = prev - nums[i];
    int absDiff = abs(diff);

    if (absDiff < 1 || absDiff > 3) return false;

    if (order == 0) {
      if (diff > 0) order = 1;
      else if (diff < 0) order = 2;
    } else {
      if ((diff > 0 && order == 2) || (diff < 0 && order == 1)) {
        return false;
      }
    }
    prev = nums[i];
  }
  return true;
}

int main(int argc, char *argv[]) {
  std::ifstream file("2.txt");

  if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return 1;
  }

  std::string line;
  std::vector<std::vector<int>> reports;
  while (std::getline(file, line)) {
    std::vector<int> report;
    size_t pos = 0;
    int level;
    while((pos = line.find(' ')) != std::string::npos) {
      level = std::stoi(line.substr(0, pos));
      report.push_back(level);
      line.erase(0, pos + 1);
    }
    report.push_back(std::stoi(line));
    reports.push_back(report);
  }

  file.close();

  int safeCount = 0;
  for (const std::vector<int>& report : reports) {
    if (isValidSequence(report)) safeCount++;
  }
  std::cout << "part one: " << safeCount << std::endl;

  safeCount = 0;
  for (const std::vector<int>& report : reports) {
    bool safe = isValidSequence(report);
    if (!safe) {
      for (size_t i = 0; i < report.size() && !safe; i++) {
        std::vector<int> modified = report;
        modified.erase(modified.begin() + i);
        if (isValidSequence(modified)) {
          safe = true;
        }
      }
    }
    if (safe) safeCount++;
  }
  std::cout << "part two: " << safeCount << std::endl;

  return 0;
}
