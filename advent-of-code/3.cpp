#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
#include <fstream>
#include <string>

void solve_part(bool is_part_two) {
  std::ifstream file("3.txt");
  std::vector<std::pair<int, int>> multiplications;
  std::string line;
  bool skip_next = false;
  static const std::unordered_set<char> digits{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  while (std::getline(file, line)) {
    size_t pos = 0;
    while ((pos = line.find("mul(", pos)) != std::string::npos) {
      if (is_part_two) {
        std::string prefix = line.substr(0, pos);
        size_t dont_pos = prefix.rfind("don't()");
        size_t do_pos = prefix.rfind("do()");

        if (dont_pos != std::string::npos || do_pos != std::string::npos) {
          if (dont_pos == std::string::npos) skip_next = false;
          else if (do_pos == std::string::npos) skip_next = true;
          else skip_next = (dont_pos > do_pos);
        }
      }

      size_t expr_start = pos + 4;
      size_t i = expr_start;
      bool valid = true;
      int numbers_seen = 0;
      char expected = 'X';

      while (valid && i < line.length()) {
        if (expected == 'X') {
          if (digits.find(line[i]) != digits.end()) {
            expected = (numbers_seen == 1) ? ')' : ',';
          } else {
            valid = false;
          }
        } else if (expected == ',') {
          if (line[i] == ',') {
            expected = 'X';
            numbers_seen++;
          } else if (digits.find(line[i]) != digits.end()) {
            expected = ',';
          } else {
            valid = false;
          }
        } else if (expected == ')') {
          if (line[i] == ')') {
            i++;
            break;
          } else if (digits.find(line[i]) != digits.end()) {
            expected = ')';
          } else {
            valid = false;
          }
        }
        i++;
      }

      if (valid && !skip_next) {
        std::string expr = line.substr(expr_start, i - expr_start - 1);
        size_t comma_pos = expr.find(',');
        try {
          int first = std::stoi(expr.substr(0, comma_pos));
          int second = std::stoi(expr.substr(comma_pos + 1));
          multiplications.emplace_back(first, second);
        } catch (const std::exception&) {}
      }
      pos++;
    }
  }

  int sum = 0;
  for (const auto& [a, b] : multiplications) {
    sum += a * b;
  }

  std::cout << "Part " << (is_part_two ? "two: " : "one: ") << sum << std::endl;
}

int main() {
  solve_part(0);
  solve_part(1);
  return 0;
}
