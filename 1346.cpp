#include <iostream>
#include <set>
#include <vector>

class Solution { // Dec 01, 2024
public:
  bool checkIfExist(std::vector<int>& arr) {
    std::set<int> toFind;
    for(int i : arr) {
      if(toFind.find(i) != toFind.end()) return true;
      toFind.insert(i*2);
      if ((double)i / 2 == (int)((double)i / 2)) toFind.insert(i/2);
    }
    return false;
  }
};

void testSolution(std::vector<int> arr, bool expected) {
  Solution res;
  int ans = res.checkIfExist(arr);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "arr: ";
  for(int i : arr) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({10,2,5,3}, true);
  testSolution({3,1,7,11}, false);
}
