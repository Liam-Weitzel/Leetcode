#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int minMaxDifference(int num) {
    std::string s = std::to_string(num);
    std::vector<std::vector<int>> freqMap(10, std::vector<int>(0));
    for(int i = 0; i < s.size(); i++) {
      freqMap[s[i]-'0'].push_back(i);
    }

    //find max value (remap first non 9 charachter to 9)
    int firstNonNine = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] != '9') {
        firstNonNine = i;
        break;
      }
    }

    std::string largestS = s;
    for(int i : freqMap[s[firstNonNine]-'0']) largestS[i] = '9';
    int largest = std::stoi(largestS);

    //find min value (remap first non 0 character to 0)
    int firstNonZero = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] != '0') {
        firstNonZero = i;
        break;
      }
    }

    std::string smallestS = s;
    for(int i : freqMap[s[firstNonZero]-'0']) smallestS[i] = '0';
    int smallest = std::stoi(smallestS);

    return largest - smallest;
  }
};

void testSolution(int num, int expected) {
  Solution res;
  int ans = res.minMaxDifference(num);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Num: " << num << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution(11891, 99009);
  testSolution(90, 99);
}
