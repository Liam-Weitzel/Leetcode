#include <string>

class Solution { // Oct 14, 2026
public:
  std::string maxSumOfSquares(int num, int sum) {
    // ns number of digits = num
    // ns sum of digits = sum
    //
    // so we are looking for a number with num digits whos digits equal to sum
    // find the integer with max score
    //
    // max score = sum of squares of digits in n
    //
    // the max sum of squares will simply be 9 and as they are added we simply need the number which fulfills the criteria with the highest individual digits?
    //
    // so maybe we can greedily construct the best integer n
    //
    // the number of digits in n is exactly num. doesnt matter, that just limits the length
    // the sum of digits in n is exactly sum means just that we always pick the highest first and minus that from the remaining sum.
    //
    // so if num = 2 and sum = 3, 
    // we start at index 1, here we pick 3 as we cant go higher
    // next we have sum = 0 and index 2, so we pick 0.

    std::string res = "";

    for(int i = 1; i <= num; ++i) {
      res += '0' + std::min(9, sum);
      sum -= std::min(9, sum);
    }

    if (sum != 0) return "";

    return res;
  }
};
