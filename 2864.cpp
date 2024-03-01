#include <iostream>
#include <memory>
#include <string>

class Solution { // Mar 01, 2024
public:
  std::string maximumOddBinaryNumber(std::string s) {
    int ones = -1;
    for(char i : s) if(i == '1') ones++;

    std::string res(s.size(), '0');
    if(ones == -1) return res;

    res.back() = '1';
    for(int i = 0; i < ones; ++i) {
      res[i] = '1';
    }

    return res;  
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::cout << res->maximumOddBinaryNumber("000011") << std::endl;
  return 0;
}
