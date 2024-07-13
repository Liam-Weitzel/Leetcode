#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

class Solution { // Jul 13, 2024
public:
  std::vector<int> survivedRobotsHealths(std::vector<int> &positions, std::vector<int> &healths, std::string directions) {
    std::vector<std::tuple<int, int, char, int>> sorted;
    for(int i = 0; i < positions.size(); i++) sorted.push_back(std::make_tuple(positions[i], healths[i], directions[i], i));
    std::sort(sorted.begin(), sorted.end());
    
    std::deque<std::tuple<int, char, int>> q;
    for(int i = 0; i < sorted.size(); i++) q.push_back(std::make_tuple(std::get<1>(sorted[i]), std::get<2>(sorted[i]), std::get<3>(sorted[i])));

    std::stack<std::tuple<int, char, int>> s;

    while(!q.empty()) {
      std::tuple<int, char, int> curr = q.front();
      q.pop_front();
      if(s.size() > 0 && std::get<1>(s.top()) == 'R' && std::get<1>(curr) == 'L') {
        if(std::get<0>(s.top()) > std::get<0>(curr)) {
          std::get<0>(s.top())--;
          q.push_front(s.top());
          s.pop();
        } else if(std::get<0>(s.top()) < std::get<0>(curr)) {
          s.pop();
          std::get<0>(curr)--;
          q.push_front(curr);
        } else {
          s.pop();
        }
      } else {
        s.push(curr);
      }
    }

    std::vector<std::pair<int, int>> survivors;
    while(!s.empty()) {
      survivors.push_back(std::make_pair(std::get<2>(s.top()), std::get<0>(s.top())));
      s.pop();
    }

    sort(survivors.begin(), survivors.end());
    std::vector<int> res;
    for(std::pair<int, int> i : survivors) res.push_back(i.second);

    return res;
  }
};

void testSolution(std::vector<int> positions, std::vector<int> healths, std::string directions, std::vector<int> expected) {
  Solution res;
  std::vector<int> ans = res.survivedRobotsHealths(positions, healths, directions);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Positions: ";
  for(int i : positions) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Healths: ";
  for(int i : healths) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Directions: " << directions << std::endl;

  std::cout << "Output: ";
  for(int i : ans) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Expected: ";
  for(int i : expected) std::cout << i << ", ";
  std::cout << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({5,4,3,2,1}, {2,17,9,15,10}, "RRRRR", {2,17,9,15,10});
  testSolution({3,5,2,6}, {10,10,15,12}, "RLRL", {14});
  testSolution({1,2,5,6}, {10,10,11,11}, "RLRL", {});
}
