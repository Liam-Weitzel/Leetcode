#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

class Solution { // Oct 13, 2026
public:
  std::vector<std::string> readBinaryWatch(int turnedOn) {
    //we can just have 10 bit input lets say. the first four represent the hours (0-11) and the last 6 represent the minutes (0-59)
    //if int turnedOn is 3 lets say we set the input to 0000000111 and then find all permutations of that. this gives us the BINARY representation
    //of those hours. This saves us having to iterate through all possible times.
    //then we convert to string/ 24 hour format and push back to res.
    //to find all possible permutations its still O(n*n!) i think with dfs/ backtracking.
    //actually no, way less as we don't care about positional order.

    std::vector<int> bits(10, 0);
    fill(bits.end() - turnedOn, bits.end(), 1);
    std::vector<std::string> res;

    do {
      std::bitset<4> hours;
      std::bitset<6> minutes;

      for (int i = 0; i < 4; ++i)
        hours[i] = bits[i];

      for (int i = 0; i < 6; ++i)
        minutes[i] = bits[i + 4];

      int h = hours.to_ulong();
      int m = minutes.to_ulong();

      if (h >= 12 || m >= 60)
        continue;

      std::string time = std::to_string(h) + ":";
      if (m < 10)
        time += "0";

      time += std::to_string(m);
      res.push_back(time);
    } while (std::next_permutation(bits.begin(), bits.end()));

    return res;
  }
};
