#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

class Solution { // Jun 13, 2024
public:
  int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());
    int res = 0;
    for(int i = 0; i < seats.size(); i++) res += std::abs(seats[i] - students[i]);
    return res;
  }
};

void testSolution(std::vector<int> seats, std::vector<int> students, int expected) {
  Solution res;
  int ans = res.minMovesToSeat(seats, students);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Seats: ";
  for(int i : seats) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Students: ";
  for(int i : students) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Answer: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({3,1,5}, {2,7,4}, 4);
  testSolution({4,1,5,9}, {1,3,2,6}, 7);
  testSolution({2,2,6,6}, {1,3,2,6}, 4);
  testSolution({12,14,19,19,12}, {19,2,17,20,7}, 19);
}
