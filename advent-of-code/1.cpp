#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream file("1.txt");
  std::string line;
  std::vector<int> left_list, right_list;

  if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return 1;
  }

  while (std::getline(file, line)) {
    int end_of_left = line.find("   ");
    int start_of_right = end_of_left+3;
    left_list.push_back(stoi(line.substr(0, end_of_left)));
    right_list.push_back(stoi(line.substr(start_of_right, line.size()-start_of_right)));
  }

  file.close();

  std::sort(left_list.begin(), left_list.end());
  std::sort(right_list.begin(), right_list.end());

  int ans = 0;
  for(int i = 0; i < left_list.size(); i++) {
    ans += abs(left_list[i] - right_list[i]);
  }

  std::cout << "part one: " << ans << std::endl;

  std::unordered_map<int, int> frequency_map_right;

  for(int i = 0; i < left_list.size(); i++) {
    frequency_map_right[right_list[i]]++;
  }

  int similarity = 0;
  for(int i = 0; i < left_list.size(); i++) {
    similarity += left_list[i] * frequency_map_right[left_list[i]];
  }

  std::cout << "part two: " << similarity << std::endl;

  return 0;
}
