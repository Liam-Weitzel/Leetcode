#include <iostream>
#include <numeric>
#include <vector>

class Solution { // Jun 21, 2024
public:
  int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
    std::vector<int> unsatisfiedCustomers(customers.begin(), customers.end());
    std::vector<int> satisfiedCustomers(customers.begin(), customers.end());

    for(int i = 0; i < grumpy.size(); i++) {
      if(grumpy[i] == 0) unsatisfiedCustomers[i] = 0;
      else if(grumpy[i] == 1) satisfiedCustomers[i] = 0;
    }

    // for(int i : unsatisfiedCustomers) std::cout << i << ", ";
    // std::cout << std::endl << std::endl;

    // for(int i : satisfiedCustomers) std::cout << i << ", ";
    // std::cout << std::endl << std::endl;

    int maxIndex = 0;
    int maxSum = 0;
    for(int i = 0; i < grumpy.size(); i++) {
      std::vector<int>::iterator start = unsatisfiedCustomers.begin()+i;
      std::vector<int>::iterator end = std::min(unsatisfiedCustomers.begin()+i+minutes, unsatisfiedCustomers.end());
      int satisfiableCustomers = std::accumulate(start, end, 0);
      if(maxSum < satisfiableCustomers) {
        maxIndex = i;
        maxSum = satisfiableCustomers;
      }
    }

    // for(int i : satisfiableCustomers) std::cout << i << ", ";
    // std::cout << std::endl << std::endl;

    return std::accumulate(satisfiedCustomers.begin(), satisfiedCustomers.end(), maxSum);
  }
};

void testSolution(std::vector<int> customers, std::vector<int> grumpy, int minutes, int expected) {
  Solution res;
  int ans = res.maxSatisfied(customers, grumpy, minutes);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "customers: ";
  for(int i : customers) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "grumpy: ";
  for(int i : grumpy) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "minutes: " << minutes << std::endl;

  std::cout << "expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({1,0,1,2,1,1,7,5}, {0,1,0,1,0,1,0,1}, 3, 16);
  testSolution({1}, {0}, 1, 1);
}
