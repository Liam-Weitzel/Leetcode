#include <cmath>
#include <iostream>
#include <map>
#include <vector>

class Solution { // Apr 20, 2025
public:
  int numRabbits(std::vector<int>& answers) {
    std::map<int, int> rabbits;
    int res = 0;

    for(int i : answers) {
      if(i == 0) res++;
      else rabbits[i]++;
    }
    
    for(std::pair<int, int> i : rabbits) {
      int pairs = ceil((double) i.second / (double) (i.first+1));
      res += (i.first+1)*pairs;
    }
    return res;
  }
};

void testSolution(std::vector<int> answers, int expected) {
  Solution res;
  int ans = res.numRabbits(answers);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Answers: ";
  for(int i : answers) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Ans: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,1,2}, 5);
  testSolution({10,10,10}, 11);
  testSolution({1,0,1,0,0}, 5);
  testSolution({0,0,1,1,1}, 6);
  testSolution({0,0,2,2,2,2,2,2,2}, 11);
  testSolution({2,2,1}, 5);
}
