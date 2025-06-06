#include <cstring>
#include <iostream>
#include <vector>

class Solution { // Jun 06, 2025
public:
  std::string robotWithString(std::string s) {
    std::vector<int> freq(26, 0);
    int low = 0;
    std::string p, t;

    for(auto i : s) {
      freq[i - 'a']++;
    }

    for(auto i : s) {
      t += i;
      freq[i - 'a']--;

      while(low < 25 && freq[low] == 0) {
        low++;
      }

      while(!t.empty() && low >= t.back() - 'a') {
        p += t.back();
        t.pop_back();
      }
    }

    return p;
}
};

void testSolution(std::string s, std::string expected) {
  Solution res;
  std::string ans = res.robotWithString(s);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "S: " << s << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("zza", "azz");
  testSolution("bac", "abc");
  testSolution("bdda", "addb");
}
