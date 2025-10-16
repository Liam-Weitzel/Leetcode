#include <iostream>
#include <map>
#include <ostream>
#include <vector>

class Solution { // Oct 16, 2025
private:
  int getBaseInt(int i, int value) {
    if (i < 0) { // because c++ does modulo with negative numbers weirdly
      int x = (-i + value - 1) / value; // ceiling division for integers
      i += value * x;
    }
    return i % value;
  }

public:
  int findSmallestInteger(std::vector<int>& nums, int value) {
    // nums = [1,-10,7,13,6,8], value = 5
    // 1, 6, 11, 16, 21 ...
    // 0, 5, 10, 15, 20 ...
    // 2, 7, 12, 17, 22 ...
    // 3, 8, 13, 18, 23 ...
    // 1, 6, 11, 16, 21 ...
    // 3, 8, 13, 18, 23 ...
    // 0,1,2,3...6 -> res = 4
    // we get the base number for each index
    // base number is the number closest to 0
    // then greedily use these number to get the highest possible sequence from 0
    // need a private func to check what base number is needed to make x

    std::map<int, int> freqCount;

    for(int i : nums) {
      std::cout << getBaseInt(i, value) << std::endl;
      freqCount[getBaseInt(i, value)]++;
    }

    int res = 0;
    while(true) {
      int& i = freqCount[getBaseInt(res, value)];
      if(i > 0) {
        res++;
        i--;
      }
      else {
        return res;
      }
    }
  }
};
