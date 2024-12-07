#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>
#include <queue>

std::vector<int> topological_sort(std::vector<int> update, std::map<int, std::vector<int>> rules) {
  std::map<int, std::vector<int>> adj;
  std::map<int, int> in_degree;

  for (int num : update) {
    adj[num] = std::vector<int>();
    in_degree[num] = 0;
  }

  for (std::pair<int, std::vector<int>> rule : rules) {
    int from = rule.first;
    for (int to : rule.second) {
      if (std::find(update.begin(), update.end(), from) != update.end() && 
          std::find(update.begin(), update.end(), to) != update.end()) {
        adj[from].push_back(to);
        in_degree[to]++;
      }
    }
  }

  std::queue<int> q;
  std::vector<int> result;

  for (std::pair<int, int> pair : in_degree) {
    if (pair.second == 0) {
      q.push(pair.first);
    }
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    result.push_back(curr);

    for (int next : adj[curr]) {
      in_degree[next]--;
      if (in_degree[next] == 0) {
        q.push(next);
      }
    }
  }

  return result;
}

bool is_update_valid(const std::vector<int>& update, const std::map<int, std::vector<int>>& rules) {
  for (size_t i = 0; i < update.size(); i++) {
    for (size_t j = i + 1; j < update.size(); j++) {
      int first = update[i];
      int second = update[j];

      if (rules.count(second) > 0) {
        std::vector<int> must_come_after = rules.at(second);
        if (std::find(must_come_after.begin(), must_come_after.end(), first) != must_come_after.end()) {
          return false;
        }
      }
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  std::ifstream file("5.txt");
  std::string line;

  std::map<int, std::vector<int>> rules;
  std::vector<std::vector<int>> updates;
  bool parsing_rules = true;

  while (std::getline(file, line)) {
    if (line.empty()) {
      parsing_rules = false;
      continue;
    }

    if (parsing_rules) {
      size_t delimiter = line.find('|');
      int from = std::stoi(line.substr(0, delimiter));
      int to = std::stoi(line.substr(delimiter + 1));
      rules[from].push_back(to);
    } else {
      std::vector<int> update;
      std::stringstream ss(line);
      std::string number;

      while (std::getline(ss, number, ',')) {
        update.push_back(std::stoi(number));
      }
      updates.push_back(update);
    }
  }

  file.close();

  std::cout << "Rules" << std::endl;
  for(std::pair<int, std::vector<int>> rule : rules) {
    std::cout << rule.first << " : ";
    for(int i : rule.second) std::cout << i << ", ";
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Updates" << std::endl;
  for(std::vector<int> update : updates) {
    for(int i : update) std::cout << i << ", ";
    std::cout << std::endl;
  }

  std::vector<std::vector<int>> valid_updates;
  for(std::vector<int> update : updates) {
    if(is_update_valid(update, rules)) valid_updates.push_back(update);
  }

  int sum_middle_page_number = 0;
  for(std::vector<int> valid_update : valid_updates) {
    sum_middle_page_number += *(valid_update.begin() + (valid_update.size()/2));
  }

  std::cout << "part 1: " << sum_middle_page_number << std::endl;

  std::vector<std::vector<int>> invalid_updates;
  for (std::vector<int> update : updates) {
    if (!is_update_valid(update, rules)) {
      std::vector<int> sorted_update = topological_sort(update, rules);
      invalid_updates.push_back(sorted_update);
    }
  }

  sum_middle_page_number = 0;
  for (std::vector<int> invalid_update : invalid_updates) {
    sum_middle_page_number += invalid_update[invalid_update.size() / 2];
  }

  std::cout << "part 2: " << sum_middle_page_number << std::endl;

  return 0;
}
