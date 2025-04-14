#include <vector>
#include <iostream>

class Solution { // Apr 14, 2025
public:
  int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
      for(int j = i+1; j < arr.size(); j++) {
        for(int k = j+1; k < arr.size(); k++) {
          if(std::abs(arr[i] - arr[j]) <= a &&
             std::abs(arr[j] - arr[k]) <= b &&
             std::abs(arr[i] - arr[k]) <= c) count++;
        }
      }
    }
    return count;
  }
};
;

void testSolution(std::vector<int> arr, int a, int b, int c, int expected) {
  Solution res;
  int ans = res.countGoodTriplets(arr, a, b, c);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "input: ";
  for(int i : arr) std::cout << i << ", ";
  std::cout << std::endl;

  std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;

  std::cout << "Answer: " << ans << std::endl;

  std::cout << "Expected: " << expected << std::endl;
  std::cout << "\033[0m" << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({3,0,1,1,9,7}, 7, 2, 3, 4);
  testSolution({1,1,2,2,3}, 0, 0, 1, 0);
}
