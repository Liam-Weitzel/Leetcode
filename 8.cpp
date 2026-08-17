#include <climits>
#include <set>
#include <string>
#include <vector>

class Solution { // Aug 17, 2026
public:
  int myAtoi(std::string s) {
    // oh my goodness what an ugly problem & solution...
    std::vector<int> res;
    std::set<char> allowed = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '+', '-'};
    int leading = true;
    int sign = 0;
    int seen = 0;

    for(char i : s) {
      if(allowed.contains(i)) {
        if(i == ' ') {
          if(seen == 0) continue;
          else break;
        }
        else if(i == '-') {
          if(sign == 0 && seen == 0) sign = -1;
          else break;
          seen++;
        }
        else if(i == '+') {
          if(sign == 0 && seen == 0) sign = 1;
          else break;
          seen++;
        }
        else {
          seen++;
          int intI = i - '0';

          if(intI == 0 && leading == true)
            continue;
          else {
            leading = false;
            res.push_back(intI);
          }
        }
      } else {
        break;
      }
    }

    std::cout << sign << std::endl;
    for(int i : res) std::cout << i;

    long long final = 0;

    for(int cur : res) {
      final = final * 10 + cur;

      if(sign == -1 && final > 2147483648LL)
        return INT_MIN;

      if(sign != -1 && final > INT_MAX)
        return INT_MAX;
    }

    if(sign == -1)
      return -final;

    return final;
  }
};
